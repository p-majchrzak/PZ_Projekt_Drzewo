/**
 * @file Node.h
 * @brief Deklaracja struktury węzła dla drzewa BST.
 */

#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * @brief Reprezentuje pojedynczy węzeł w binarnym drzewie poszukiwań (BST).
 * 
 * Klasa przechowuje wartość całkowitą oraz wskaźniki na swoich potomków 
 * (lewe i prawe poddrzewo).
 */
class Node {
public:
    int data;    ///< Wartość całkowita (int) przechowywana w węźle.
    Node* left;  ///< Wskaźnik na lewe dziecko (węzły z wartościami mniejszymi).
    Node* right; ///< Wskaźnik na prawe dziecko (węzły z wartościami większymi).

    /**
     * @brief Konstruktor inicjalizujący nowy węzeł.
     * 
     * Tworzy węzeł z zadaną wartością i ustawia wskaźniki left oraz right na nullptr.
     * Słowo kluczowe explicit zapobiega niejawnym konwersjom typów.
     * 
     * @param value Wartość, która ma zostać przypisana do węzła.
     */
    explicit Node(int value);
};

#endif