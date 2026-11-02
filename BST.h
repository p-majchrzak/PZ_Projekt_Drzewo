#ifndef BST_H
#define BST_H
#include "Node.h"

class BST {
private:
    Node* root;
    
    // Prywatne metody pomocnicze do rekurencji
    Node* insertRecursive(Node* node, int value);
    Node* removeRecursive(Node* node, int value);
    Node* findMin(Node* node);
    void clearRecursive(Node* node);
    void printPreOrder(Node* node);
    void printInOrder(Node* node);
    void printPostOrder(Node* node);

public:
    BST();
    void insert(int value);
    void remove(int value);
    void clear();
    void findPath(int value);
    void displayTree();
};

#endif