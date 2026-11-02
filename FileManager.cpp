#include "FileManager.h"
#include "BST.h"
#include "Node.h"

#include <cstdint>
#include <fstream>
#include <istream>
#include <limits>
#include <ostream>
#include <vector>

// Zapis drzewa do pliku tekstowego

bool FileManager::saveText(
    const BST& tree,
    const std::string& filename
) {
    std::ofstream file(filename);

    if (!file) {
        return false;
    }

    std::vector<const Node*> stack;

    const Node* current = tree.root;

    bool first = true;

    while (current != nullptr || !stack.empty()) {

        while (current != nullptr) {
            stack.push_back(current);
            current = current->left;
        }

        current = stack.back();
        stack.pop_back();

        if (!first) {
            file << " ";
        }

        file << current->data;

        first = false;

        current = current->right;
    }

    file << "\n";

    return file.good();
}

// Wczytywanie danych z pliku tekstowego

bool FileManager::loadText(
    BST& tree,
    const std::string& filename,
    bool clearFirst
) {
    std::ifstream file(filename);

    if (!file) {
        return false;
    }

    std::vector<int> values;

    long long value;

    while (file >> value) {

        if (value < std::numeric_limits<int>::min() ||
            value > std::numeric_limits<int>::max()) {

            return false;
        }

        values.push_back(static_cast<int>(value));
    }

    if (!file.eof()) {
        return false;
    }

    if (clearFirst) {
        tree.clear();
    }

    for (int number : values) {
        tree.insert(number);
    }

    return true;
}

// Zapis pojedynczego wezla do pliku binarnego

bool FileManager::writeNode(
    std::ostream& file,
    const Node* node
) {
    std::uint8_t marker = (node == nullptr) ? 0 : 1;

    file.write(
        reinterpret_cast<const char*>(&marker),
        sizeof(marker)
    );

    if (node == nullptr) {
        return file.good();
    }

    std::int32_t value = node->data;

    file.write(
        reinterpret_cast<const char*>(&value),
        sizeof(value)
    );

    return file.good() &&
           writeNode(file, node->left) &&
           writeNode(file, node->right);
}

// Odczyt pojedynczego wezla z pliku binarnego

Node* FileManager::readNode(
    std::istream& file,
    bool& valid
) {
    std::uint8_t marker = 0;

    file.read(
        reinterpret_cast<char*>(&marker),
        sizeof(marker)
    );

    if (!file) {
        valid = false;
        return nullptr;
    }

    if (marker == 0) {
        return nullptr;
    }

    if (marker != 1) {
        valid = false;
        return nullptr;
    }

    std::int32_t value = 0;

    file.read(
        reinterpret_cast<char*>(&value),
        sizeof(value)
    );

    if (!file ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {

        valid = false;
        return nullptr;
    }

    Node* node = new Node(static_cast<int>(value));

    node->left = readNode(file, valid);

    if (valid) {
        node->right = readNode(file, valid);
    }

    if (!valid) {

        std::vector<Node*> pending{node};

        while (!pending.empty()) {

            Node* current = pending.back();
            pending.pop_back();

            if (current->left) {
                pending.push_back(current->left);
            }

            if (current->right) {
                pending.push_back(current->right);
            }

            delete current;
        }

        return nullptr;
    }

    return node;
}

// Zapis calego drzewa binarnie

bool FileManager::saveBinary(
    const BST& tree,
    const std::string& filename
) {
    std::ofstream file(filename, std::ios::binary);

    if (!file) {
        return false;
    }

    const char signature[4] = {'B', 'S', 'T', '1'};

    file.write(signature, sizeof(signature));

    return file.good() &&
           writeNode(file, tree.root) &&
           file.good();
}

// Odczyt calego drzewa binarnie

bool FileManager::loadBinary(
    BST& tree,
    const std::string& filename
) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        return false;
    }

    char signature[4]{};

    file.read(signature, sizeof(signature));

    if (!file ||
        signature[0] != 'B' ||
        signature[1] != 'S' ||
        signature[2] != 'T' ||
        signature[3] != '1') {

        return false;
    }

    bool valid = true;

    Node* newRoot = readNode(file, valid);

    if (!valid || file.peek() != std::char_traits<char>::eof()) {

        std::vector<Node*> pending;

        if (newRoot) {
            pending.push_back(newRoot);
        }

        while (!pending.empty()) {

            Node* current = pending.back();
            pending.pop_back();

            if (current->left) {
                pending.push_back(current->left);
            }

            if (current->right) {
                pending.push_back(current->right);
            }

            delete current;
        }

        return false;
    }

    tree.clear();

    tree.root = newRoot;

    return true;
}