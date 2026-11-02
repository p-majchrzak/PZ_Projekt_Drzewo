#include "BST.h"
#include <iostream>

BST::BST() {
    root = nullptr;
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
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }
    
    return node;
}

void BST::remove(int value) {
    root = removeRecursive(root, value);
}

Node* BST::removeRecursive(Node* node, int value) {
    if (node == nullptr) return node;

    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    } else {
        // Węzeł z jednym dzieckiem lub bez dzieci
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        // Węzeł z dwojgiem dzieci: pobierz najmniejszy w prawym poddrzewie
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }
    return node;
}

Node* BST::findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
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
void BST::findPath(int value) {
    Node* current = root;
    std::cout << "Droga do elementu " << value << ": ";
    bool found = false;
    
    while (current != nullptr) {
        std::cout << current->data << " ";
        if (current->data == value) {
            found = true;
            break;
        }
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (found) {
        std::cout << "- Znaleziono!\n";
    } else {
        std::cout << "- Brak elementu w drzewie.\n";
    }
}
void BST::printPreOrder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void BST::printInOrder(Node* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

void BST::printPostOrder(Node* node) {
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->data << " ";
}

void BST::displayTree() {
    int choice;
    std::cout << "\nWybierz metode wyswietlania drzewa:\n";
    std::cout << "1. Pre-order (Korzen - Lewe - Prawe)\n";
    std::cout << "2. In-order (Lewe - Korzen - Prawe)\n";
    std::cout << "3. Post-order (Lewe - Prawe - Korzen)\n";
    std::cout << "Wybierz opcje: ";
    std::cin >> choice;

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