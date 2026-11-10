#include "FileManager.h"
#include "BST.h"
#include "Node.h"

#include <cstdint>
#include <fstream>
#include <istream>
#include <limits>
#include <ostream>
#include <vector>

/**
 * @brief Zapisuje drzewo BST do pliku tekstowego w porządku in-order.
 * @param tree Referencja do zapisywanego drzewa BST.
 * @param filename Ścieżka do pliku tekstowego.
 * @return true jeśli zapis powiódł się, false w przeciwnym wypadku.
 */
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

/**
 * @brief Wczytuje dane z pliku tekstowego i buduje z nich drzewo BST.
 * @param tree Referencja do drzewa BST, do którego zostaną wczytane dane.
 * @param filename Ścieżka do pliku tekstowego.
 * @param clearFirst Określa, czy wyczyścić istniejące drzewo przed wczytaniem nowych danych.
 * @return true jeśli wczytywanie powiodło się, false w przeciwnym wypadku.
 */
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

/**
 * @brief Rekurencyjnie zapisuje pojedynczy węzeł oraz jego potomków do strumienia binarnego.
 * @param file Strumień wyjściowy pliku binarnego.
 * @param node Wskaźnik na zapisywany węzeł.
 * @return true jeśli zapis przebiegł pomyślnie, false w przeciwnym wypadku.
 */
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

/**
 * @brief Rekurencyjnie odczytuje pojedynczy węzeł ze strumienia binarnego.
 * @param file Strumień wejściowy pliku binarnego.
 * @param valid Referencja do flagi określającej poprawność struktury i danych.
 * @return Node* Wskaźnik na nowo utworzony węzeł lub nullptr w przypadku błędu.
 */
Node* FileManager::readNode(
    std::istream& file,
    bool& valid
) {
    if (!valid) return nullptr;

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

    if (!file) {
        valid = false;
        return nullptr;
    }

    Node* node = new Node(static_cast<int>(value));

    node->left = readNode(file, valid);
    node->right = readNode(file, valid);

    return node;
}

/**
 * @brief Zapisuje całe drzewo BST w formacie binarnym do pliku.
 * @param tree Referencja do zapisywanego drzewa BST.
 * @param filename Ścieżka do pliku binarnego.
 * @return true jeśli zapis powiódł się, false w przeciwnym wypadku.
 */
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

/**
 * @brief Wczytuje całe drzewo BST z pliku binarnego.
 * @param tree Referencja do drzewa BST, do którego zostaną wczytane dane.
 * @param filename Ścieżka do pliku binarnego.
 * @return true jeśli odczyt powiódł się, false w przeciwnym wypadku.
 */
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

    if (!valid) {

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