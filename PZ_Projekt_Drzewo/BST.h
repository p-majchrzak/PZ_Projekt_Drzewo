/**
 * @file BST.h
 * @brief Deklaracja klasy BST reprezentującej binarne drzewo poszukiwań (Binary Search Tree).
 */

#ifndef BST_H
#define BST_H
#include "Node.h"

/**
 * @class BST
 * @brief Klasa zarządzająca drzewem BST.
 * 
 * Zapewnia interfejs do wstawiania, usuwania, wyszukiwania drogi do elementu 
 * oraz różnego rodzaju wypisywania zawartości drzewa na ekran.
 */
class BST {
private:
    Node* root; ///< Wskaźnik na główny węzeł (korzeń) drzewa.

    /**
     * @brief Rekurencyjna funkcja pomocnicza do dodawania nowego węzła.
     * 
     * @param node Aktualnie sprawdzany węzeł.
     * @param value Wartość do wstawienia.
     * @return Wskaźnik na węzeł po wstawieniu nowej wartości.
     */
    Node* insertRecursive(Node* node, int value);

    /**
     * @brief Rekurencyjna funkcja pomocnicza do usuwania węzła z drzewa.
     * 
     * @param node Aktualnie sprawdzany węzeł.
     * @param value Wartość do usunięcia.
     * @return Wskaźnik na węzeł po usunięciu wybranej wartości.
     */
    Node* removeRecursive(Node* node, int value);

    /**
     * @brief Znajduje węzeł z najmniejszą wartością w danym poddrzewie.
     * 
     * Wykorzystywane głównie przy usuwaniu węzłów posiadających dwoje dzieci.
     * 
     * @param node Węzeł, od którego rozpoczynamy szukanie (korzeń poddrzewa).
     * @return Wskaźnik na węzeł z najmniejszą wartością.
     */
    Node* findMin(Node* node);

    /**
     * @brief Rekurencyjna funkcja pomocnicza czyszcząca całe poddrzewo.
     * 
     * @param node Węzeł, od którego zaczynamy usuwanie elementów.
     */
    void clearRecursive(Node* node);

    /**
     * @brief Rekurencyjne wypisywanie drzewa w porządku Pre-Order (Korzeń-Lewe-Prawe).
     * 
     * @param node Aktualnie odwiedzany węzeł.
     */
    void printPreOrder(Node* node);

    /**
     * @brief Rekurencyjne wypisywanie drzewa w porządku In-Order (Lewe-Korzeń-Prawe).
     * 
     * @param node Aktualnie odwiedzany węzeł.
     */
    void printInOrder(Node* node);

    /**
     * @brief Rekurencyjne wypisywanie drzewa w porządku Post-Order (Lewe-Prawe-Korzeń).
     * 
     * @param node Aktualnie odwiedzany węzeł.
     */
    void printPostOrder(Node* node);

    /**
     * @brief Pomocnicza funkcja do graficznego rysowania drzewa w konsoli.
     * 
     * @param node Aktualny węzeł.
     * @param depth Aktualna głębokość (poziom) w drzewie (służy do wcięć).
     */
    void printGraphic(Node* node, int depth);

    /**
     * @brief Deklaracja przyjaźni z klasą FileManager.
     * Umożliwia klasie FileManager bezpośredni dostęp do prywatnych składowych drzewa 
     * (np. do korzenia) w celu zapisu i odczytu z pliku.
     */
    friend class FileManager;

public:
    /**
     * @brief Konstruktor domyślny.
     * Inicjalizuje puste drzewo (root = nullptr).
     */
    BST();

    /**
     * @brief Destruktor.
     * Wywołuje metodę czyszczącą drzewo przed zniszczeniem obiektu.
     */
    ~BST();

    /**
     * @brief Zablokowanie konstruktora kopiującego.
     * Zapobiega błędom związanym z podwójnym zwalnianiem pamięci.
     */
    BST(const BST&) = delete;

    /**
     * @brief Zablokowanie operatora przypisania.
     * Zapobiega niekontrolowanemu kopiowaniu struktury dynamicznej.
     */
    BST& operator=(const BST&) = delete;

    /**
     * @brief Dodaje nową wartość do drzewa BST.
     * 
     * @param value Wartość całkowita (int) do zapisania.
     */
    void insert(int value);

    /**
     * @brief Usuwa wskazaną wartość z drzewa, jeśli istnieje.
     * 
     * @param value Wartość całkowita (int) do usunięcia.
     */
    void remove(int value);

    /**
     * @brief Usuwa wszystkie elementy z drzewa zwalniając pamięć.
     */
    void clear();

    /**
     * @brief Szuka podanego elementu i wypisuje w konsoli przebytą do niego drogę.
     * 
     * @param value Szukana wartość całkowita (int).
     */
    void findPath(int value);

    /**
     * @brief Wyświetla tekstowe menu z wyborem metody przeglądu (Pre/In/Post) i wypisuje drzewo.
     */
    void displayTree();

    /**
     * @brief Wyświetla strukturalną (graficzną) reprezentację drzewa w konsoli.
     */
    void displayGraphic();
};

#endif