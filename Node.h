#ifndef NODE_H
#define NODE_H

/**
 * @brief Pojedynczy wezel drzewa BST.
 */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    explicit Node(int value);
};

#endif