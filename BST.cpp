#include "BST.h"

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