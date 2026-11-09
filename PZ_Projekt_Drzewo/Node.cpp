/**
 * @file Node.cpp
 * @brief Implementacja metod klasy Node dla drzewa BST.
 */

#include "Node.h"

/**
 * @brief Konstruktor wezla drzewa BST.
 *
 * Inicjalizuje wezel podana wartoscia oraz ustawia
 * wskazniki na lewe i prawe dziecko na nullptr.
 *
 * @param value Wartosc przechowywana w wezle.
 */
Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}