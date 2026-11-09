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
 * @class FileManager
 * @brief Klasa odpowiedzialna za obsługę plików (zapis/odczyt drzewa).
 * 
 * Klasa udostępnia statyczne metody pozwalające na zapisywanie i wczytywanie 
 * struktury drzewa BST z wykorzystaniem zarówno plików tekstowych, 
 * jak i binarnych, zgodnie z wymaganiami projektu.
 */
class FileManager {
private:
    /**
     * @brief Rekurencyjna funkcja pomocnicza zapisująca pojedynczy węzeł do strumienia pliku.
     * 
     * @param file Referencja do strumienia wyjściowego (pliku).
     * @param node Wskaźnik na węzeł do zapisania.
     * @return true jeśli zapis węzła powiódł się, false w przypadku błędu.
     */
    static bool writeNode(std::ostream& file, const Node* node);

    /**
     * @brief Rekurencyjna funkcja pomocnicza odczytująca pojedynczy węzeł ze strumienia pliku.
     * 
     * @param file Referencja do strumienia wejściowego (pliku).
     * @param valid Referencja do flagi logicznej informującej o poprawności odczytu.
     * @return Wskaźnik na nowo utworzony węzeł na podstawie danych z pliku.
     */
    static Node* readNode(std::istream& file, bool& valid);

public:
    // ==========================================
    // PLIKI TEKSTOWE
    // ==========================================

    /**
     * @brief Zapisuje zawartość drzewa BST do pliku tekstowego.
     * 
     * @param tree Referencja do stałego obiektu drzewa, które ma zostać zapisane.
     * @param filename Nazwa (lub ścieżka) pliku tekstowego docelowego.
     * @return true jeśli operacja zapisu zakończyła się sukcesem, false w przypadku błędu.
     */
    static bool saveText(
        const BST& tree,
        const std::string& filename
    );

    /**
     * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa BST.
     * 
     * @param tree Referencja do obiektu drzewa, do którego trafią wczytane dane.
     * @param filename Nazwa (lub ścieżka) pliku tekstowego do odczytu.
     * @param clearFirst Jeśli true, drzewo zostanie najpierw całkowicie wyczyszczone przed wczytaniem nowych danych.
     * @return true jeśli operacja odczytu zakończyła się sukcesem, false w przypadku błędu.
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
     * @brief Zapisuje kompletną strukturę drzewa BST do pliku w formacie binarnym.
     * 
     * @param tree Referencja do stałego obiektu drzewa, które ma zostać zapisane.
     * @param filename Nazwa (lub ścieżka) pliku binarnego.
     * @return true jeśli zapis binarny powiódł się, false w przypadku błędu otwarcia/zapisu.
     */
    static bool saveBinary(
        const BST& tree,
        const std::string& filename
    );

    /**
     * @brief Odczytuje i odtwarza strukturę drzewa BST z pliku binarnego.
     * 
     * UWAGA: Metoda domyślnie nadpisuje (czyści) aktualną zawartość przekazanego drzewa 
     * przed zbudowaniem go na nowo z pliku binarnego.
     * 
     * @param tree Referencja do obiektu drzewa, w którym odtworzona zostanie struktura.
     * @param filename Nazwa (lub ścieżka) pliku binarnego do odczytu.
     * @return true jeśli odczyt binarny i rekonstrukcja drzewa powiodły się, false w przeciwnym razie.
     */
    static bool loadBinary(
        BST& tree,
        const std::string& filename
    );
};

#endif