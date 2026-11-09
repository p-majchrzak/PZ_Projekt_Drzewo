#ifndef NODE_H
#define NODE_H

/**
 * @brief Klasa reprezentujaca pojedynczy wezel drzewa BST.
 *
 * Przechowuje wartosc oraz wskazniki na lewe i prawe dziecko.
 */
class Node {
public:
    /** @brief Wartosc przechowywana w wezle. */
    int data;

    /** @brief Wskaznik na lewe dziecko wezla. */
    Node* left;

    /** @brief Wskaznik na prawe dziecko wezla. */
    Node* right;

    /**
     * @brief Konstruktor wezla.
     *
     * Inicjalizuje wartosc oraz ustawia wskazniki dzieci na nullptr.
     *
     * @param value Wartosc przypisywana do wezla.
     */
    explicit Node(int value);
};

#endif