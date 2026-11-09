/**
 * @file FileManager.h
 * @brief Deklaracja klasy FileManager służącej do zapisu i odczytu drzewa BST z plików.
 */

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

// Deklaracje zapowiadające (forward declarations), aby uniknąć cyklicznych zależności
class BST;
class Node;

/**
 * @brief Klasa odpowiedzialna za obsluge plikow.
 *
 * Umozliwia zapisywanie i odczytywanie drzewa BST
 * w formacie tekstowym oraz binarnym.
 */
class FileManager {
private:
    /**
     * @brief Rekurencyjnie zapisuje wezel drzewa do pliku.
     * @param file Strumien wyjsciowy pliku.
     * @param node Wskaznik na zapisywany wezel.
     * @return true jesli zapis przebiegl poprawnie, false w przeciwnym razie.
     */
    static bool writeNode(std::ostream& file, const Node* node);

    /**
     * @brief Rekurencyjnie odczytuje wezel drzewa z pliku.
     * @param file Strumien wejsciowy pliku.
     * @param valid Flaga informujaca o poprawnosci odczytu.
     * @return Wskaznik na odczytany wezel.
     */
    static Node* readNode(std::istream& file, bool& valid);

public:
    // ==========================================
    // PLIKI TEKSTOWE
    // ==========================================

    /**
     * @brief Zapisuje drzewo BST do pliku tekstowego.
     * @param tree Drzewo przeznaczone do zapisania.
     * @param filename Nazwa pliku wyjsciowego.
     * @return true jesli zapis zakonczyl sie powodzeniem, false w przeciwnym razie.
     */
    static bool saveText(
        const BST& tree,
        const std::string& filename
    );

    /**
     * @brief Wczytuje drzewo BST z pliku tekstowego.
     * @param tree Drzewo, do ktorego zostana wczytane dane.
     * @param filename Nazwa pliku wejsciowego.
     * @param clearFirst Okresla, czy drzewo ma zostac wyczyszczone przed wczytaniem.
     * @return true jesli odczyt zakonczyl sie powodzeniem, false w przeciwnym razie.
     */
    static bool loadText(
        BST& tree,
        const std::string& filename,
        bool clearFirst
    );

    // ==========================================
    // PLIKI BINARNE
    // ==========================================

    /**
     * @brief Zapisuje drzewo BST do pliku binarnego.
     * @param tree Drzewo przeznaczone do zapisania.
     * @param filename Nazwa pliku wyjsciowego.
     * @return true jesli zapis zakonczyl sie powodzeniem, false w przeciwnym razie.
     */
    static bool saveBinary(
        const BST& tree,
        const std::string& filename
    );

    /**
     * @brief Wczytuje drzewo BST z pliku binarnego.
     * @param tree Drzewo, do ktorego zostana wczytane dane.
     * @param filename Nazwa pliku wejsciowego.
     * @return true jesli odczyt zakonczyl sie powodzeniem, false w przeciwnym razie.
     */
    static bool loadBinary(
        BST& tree,
        const std::string& filename
    );
};

#endif