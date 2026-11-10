#include "BST.h"
#include "FileManager.h"

#include <iostream>
#include <limits>
#include <string>

/**
 * @brief Pobiera poprawną liczbę całkowitą od użytkownika, zabezpieczając przed błędami wejścia.
 * @param message Komunikat wyświetlany użytkownikowi przed wprowadzeniem liczby.
 * @return int Wczytana wartość całkowita.
 */
int readInt(const std::string& message) {
    int value;

    while (true) {
        std::cout << message;

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Wprowadz poprawna liczbe.\n";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

/**
 * @brief Pobiera nazwę pliku od użytkownika.
 * @param message Komunikat wyświetlany użytkownikowi przed podaniem nazwy.
 * @return std::string Wczytana nazwa pliku.
 */
std::string readFilename(const std::string& message) {
    std::string filename;

    std::cout << message;
    std::cin >> filename;

    return filename;
}

/**
 * @brief Wyświetla główne menu interaktywne programu na standardowym wyjściu.
 */
void showMenu() {
    std::cout << "\n========== MENU BST ==========\n";

    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usun element\n";
    std::cout << "3. Usun cale drzewo\n";
    std::cout << "4. Szukaj drogi do elementu\n";
    std::cout << "5. Przejdz drzewo\n";
    std::cout << "6. Wyswietl drzewo graficznie\n";

    std::cout << "7. Zapisz drzewo do pliku tekstowego\n";
    std::cout << "8. Zapisz drzewo do pliku binarnego\n";
    std::cout << "9. Wczytaj drzewo z pliku binarnego\n";
    std::cout << "10. Wczytaj liczby z pliku tekstowego\n";

    std::cout << "0. Zakoncz program\n";

    std::cout << "==============================\n";
}

/**
 * @brief Główna funkcja programu sterująca działaniem pętli menu i zarządzaniem drzewem BST.
 * @return int Kod powrotu programu (0 w przypadku poprawnego zakończenia).
 */
int main() {
    BST tree;

    bool running = true;

    while (running) {
        showMenu();

        int choice = readInt("Wybierz opcje: ");

        switch (choice) {

            // Dodawanie
            case 1: {
                int value = readInt("Podaj liczbe: ");

                tree.insert(value);

                std::cout << "Dodano element (jesli nie byl duplikatem).\n";
                break;
            }

            // Usuwanie
            case 2: {
                int value = readInt("Podaj liczbe do usuniecia: ");

                tree.remove(value);

                std::cout << "Operacja usuwania zakonczona.\n";
                break;
            }

            // Czyszczenie drzewa
            case 3: {
                tree.clear();

                std::cout << "Drzewo zostalo wyczyszczone.\n";
                break;
            }

            // Wyszukiwanie drogi
            case 4: {
                int value = readInt("Podaj szukana liczbe: ");

                tree.findPath(value);
                break;
            }

            // Przechodzenie drzewa
            case 5: {
                tree.displayTree();
                break;
            }

            // Graficzne wyswietlanie
            case 6: {
                tree.displayGraphic();
                break;
            }

            // Zapis TXT
            case 7: {
                std::string filename =
                    readFilename("Podaj nazwe pliku tekstowego: ");

                if (FileManager::saveText(tree, filename)) {
                    std::cout << "Zapisano plik tekstowy.\n";
                }
                else {
                    std::cout << "Blad zapisu pliku.\n";
                }

                break;
            }

            // Zapis BIN
            case 8: {
                std::string filename =
                    readFilename("Podaj nazwe pliku binarnego: ");

                if (FileManager::saveBinary(tree, filename)) {
                    std::cout << "Zapisano plik binarny.\n";
                }
                else {
                    std::cout << "Blad zapisu pliku.\n";
                }

                break;
            }

            // Odczyt BIN
            case 9: {
                std::string filename =
                    readFilename("Podaj nazwe pliku binarnego: ");

                if (FileManager::loadBinary(tree, filename)) {
                    std::cout << "Wczytano drzewo z pliku binarnego.\n";
                }
                else {
                    std::cout << "Blad odczytu pliku binarnego.\n";
                }

                break;
            }

            // Odczyt TXT
            case 10: {
                std::string filename =
                    readFilename("Podaj nazwe pliku tekstowego: ");

                std::cout << "\n";
                std::cout << "1. Wczytaj do pustego drzewa\n";
                std::cout << "2. Dodaj do istniejacego drzewa\n";

                int mode = readInt("Wybierz tryb: ");

                if (mode != 1 && mode != 2) {
                    std::cout << "Nieprawidlowy wybor.\n";
                    break;
                }

                if (FileManager::loadText(
                    tree,
                    filename,
                    mode == 1
                )) {
                    std::cout << "Wczytano dane z pliku tekstowego.\n";
                }
                else {
                    std::cout << "Blad odczytu lub niepoprawne dane.\n";
                }

                break;
            }

            // Zamykanie programu
            case 0: {
                running = false;

                std::cout << "Zamykanie programu.\n";
                break;
            }

            default: {
                std::cout << "Nie ma takiej opcji.\n";
                break;
            }
        }

        // Oczekiwanie na ENTER przed ponownym wyswietleniem menu
        if (running) {
            std::cout << "\nNacisnij ENTER, aby powrocic do menu...";

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cin.get();
        }
    }

    return 0;
}