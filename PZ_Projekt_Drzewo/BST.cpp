#include "BST.h"
#include <iostream>

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    clear();
}

void BST::insert(int value) {
    root = insertRecursive(root, value);
}

Node* BST::insertRecursive(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

// Wyszukiwanie najmniejszego elementu

Node* BST::findMin(Node* node) {
    Node* current = node;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// Usuwanie elementu

void BST::remove(int value) {
    root = removeRecursive(root, value);
}

Node* BST::removeRecursive(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    }
    else {

        // Wezel bez lewego dziecka

        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Wezel bez prawego dziecka

        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Wezel posiada dwoje dzieci

        Node* temp = findMin(node->right);

        node->data = temp->data;

        node->right = removeRecursive(node->right, temp->data);
    }

    return node;
}

// Usuwanie calego drzewa

void BST::clear() {
    clearRecursive(root);
    root = nullptr;
}

void BST::clearRecursive(Node* node) {
    if (node != nullptr) {
        clearRecursive(node->left);
        clearRecursive(node->right);

        delete node;
    }
}

// Wyszukiwanie drogi do elementu

void BST::findPath(int value) {
    Node* current = root;

    std::cout << "Droga do elementu " << value << ": ";

    while (current != nullptr) {

        std::cout << current->data;

        if (current->data == value) {
            std::cout << " - Znaleziono!\n";
            return;
        }

        std::cout << " -> ";

        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    std::cout << "Brak elementu w drzewie.\n";
}

// Preorder

void BST::printPreOrder(Node* node) {
    if (node == nullptr) return;

    std::cout << node->data << " ";

    printPreOrder(node->left);
    printPreOrder(node->right);
}

// Inorder

void BST::printInOrder(Node* node) {
    if (node == nullptr) return;

    printInOrder(node->left);

    std::cout << node->data << " ";

    printInOrder(node->right);
}

// Postorder

void BST::printPostOrder(Node* node) {
    if (node == nullptr) return;

    printPostOrder(node->left);
    printPostOrder(node->right);

    std::cout << node->data << " ";
}

// Wybor metody przechodzenia drzewa

void BST::displayTree() {
    int choice;

    std::cout << "\nWybierz metode wyswietlania drzewa:\n";
    std::cout << "1. Pre-order (Korzen - Lewe - Prawe)\n";
    std::cout << "2. In-order (Lewe - Korzen - Prawe)\n";
    std::cout << "3. Post-order (Lewe - Prawe - Korzen)\n";
    std::cout << "Wybierz opcje: ";

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Nieprawidlowe dane.\n";
        return;
    }

    std::cout << "Zawartosc drzewa: ";

    switch (choice) {

        case 1:
            printPreOrder(root);
            break;

        case 2:
            printInOrder(root);
            break;

        case 3:
            printPostOrder(root);
            break;

        default:
            std::cout << "Nieprawidlowy wybor.";
    }

    std::cout << "\n";
}

// Graficzne wyswietlanie drzewa

void BST::printGraphic(Node* node, int depth) {
    if (node == nullptr) return;

    printGraphic(node->right, depth + 1);

    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }

    std::cout << node->data << "\n";

    printGraphic(node->left, depth + 1);
}

void BST::displayGraphic() {
    if (root == nullptr) {
        std::cout << "Drzewo jest puste.\n";
        return;
    }

    std::cout << "\nGraficzna postac drzewa:\n";

    printGraphic(root, 0);
}