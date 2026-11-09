#ifndef BST_H
#define BST_H

#include "Node.h"
<<<<<<< Updated upstream
//Test
/**
 * @brief Klasa implementujaca binarne drzewo poszukiwan.
=======

/**
 * @brief Klasa reprezentujaca drzewo binarne poszukiwan (BST).
 *
 * Klasa umozliwia dodawanie, usuwanie i wyszukiwanie elementow,
 * czyszczenie drzewa oraz wyswietlanie jego zawartosci.
>>>>>>> Stashed changes
 */
class BST {
private:
    /** @brief Wskaznik na korzen drzewa. */
    Node* root;

<<<<<<< Updated upstream
=======
    /**
     * @brief Rekurencyjnie dodaje nowy element do drzewa.
     * @param node Aktualnie odwiedzany wezel.
     * @param value Wartosc do dodania.
     * @return Wskaznik na wezel po wykonaniu operacji.
     */
>>>>>>> Stashed changes
    Node* insertRecursive(Node* node, int value);

    /**
     * @brief Rekurencyjnie usuwa element z drzewa.
     * @param node Aktualnie odwiedzany wezel.
     * @param value Wartosc do usuniecia.
     * @return Wskaznik na wezel po wykonaniu operacji.
     */
    Node* removeRecursive(Node* node, int value);

    /**
     * @brief Wyszukuje najmniejszy element w poddrzewie.
     * @param node Korzen przeszukiwanego poddrzewa.
     * @return Wskaznik na wezel o najmniejszej wartosci.
     */
    Node* findMin(Node* node);

    /**
     * @brief Rekurencyjnie usuwa wszystkie wezly poddrzewa.
     * @param node Korzen poddrzewa przeznaczonego do usuniecia.
     */
    void clearRecursive(Node* node);

    /**
     * @brief Wyswietla elementy drzewa w porzadku PreOrder.
     * @param node Aktualnie odwiedzany wezel.
     */
    void printPreOrder(Node* node);

    /**
     * @brief Wyswietla elementy drzewa w porzadku InOrder.
     * @param node Aktualnie odwiedzany wezel.
     */
    void printInOrder(Node* node);

    /**
     * @brief Wyswietla elementy drzewa w porzadku PostOrder.
     * @param node Aktualnie odwiedzany wezel.
     */
    void printPostOrder(Node* node);

    /**
     * @brief Wyswietla graficzna reprezentacje poddrzewa.
     * @param node Aktualnie odwiedzany wezel.
     * @param depth Poziom zaglebienia w drzewie.
     */
    void printGraphic(Node* node, int depth);

    /** @brief Klasa FileManager posiada dostep do prywatnych skladowych BST. */
    friend class FileManager;

public:
    /**
     * @brief Konstruktor klasy BST.
     *
     * Inicjalizuje puste drzewo binarne poszukiwan.
     */
    BST();

    /**
     * @brief Destruktor klasy BST.
     *
     * Zwalnia pamiec zajmowana przez wezly drzewa.
     */
    ~BST();

    /**
     * @brief Konstruktor kopiujacy jest zablokowany.
     */
    BST(const BST&) = delete;

    /**
     * @brief Operator przypisania kopiujacego jest zablokowany.
     * @return Referencja do obiektu BST.
     */
    BST& operator=(const BST&) = delete;

    /**
     * @brief Dodaje nowy element do drzewa.
     * @param value Wartosc przeznaczona do dodania.
     */
    void insert(int value);

    /**
     * @brief Usuwa wskazany element z drzewa.
     * @param value Wartosc przeznaczona do usuniecia.
     */
    void remove(int value);

    /**
     * @brief Usuwa wszystkie elementy drzewa.
     */
    void clear();

    /**
     * @brief Wyswietla sciezke prowadząca do wskazanego elementu.
     * @param value Wyszukiwana wartosc.
     */
    void findPath(int value);

    /**
     * @brief Wyswietla zawartosc drzewa w roznych porzadkach przechodzenia.
     */
    void displayTree();

    /**
     * @brief Wyswietla graficzna reprezentacje drzewa.
     */
    void displayGraphic();
};

#endif