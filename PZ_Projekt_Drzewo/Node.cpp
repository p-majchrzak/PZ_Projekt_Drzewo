/**
 * @file Node.cpp
 * @brief Implementacja metod klasy Node dla drzewa BST.
 */

#include "Node.h"

/**
 * @brief Konstruktor klasy Node.
 * 
 * Przypisuje węzłowi początkową wartość i inicjalizuje wskaźniki potomków (lewe i prawe dziecko) jako puste (nullptr).
 * 
 * @param value Wartość całkowita (int) przypisywana do nowego węzła.
 */
Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}