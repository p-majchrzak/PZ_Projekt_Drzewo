#ifndef BST_H
#define BST_H
#include "Node.h"

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* node, int value);
    Node* removeRecursive(Node* node, int value);
    Node* findMin(Node* node);

    void clearRecursive(Node* node);

    void printPreOrder(Node* node);
    void printInOrder(Node* node);
    void printPostOrder(Node* node);

    void printGraphic(Node* node, int depth);

    friend class FileManager;

public:
    BST();
    ~BST();

    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    void insert(int value);
    void remove(int value);
    void clear();
    void findPath(int value);

    void displayTree();
    void displayGraphic();
};

#endif

//test