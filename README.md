# Projekt – Drzewo BST

## Opis projektu

Projekt przedstawia implementację drzewa binarnego wyszukiwania (BST – Binary Search Tree) w języku C++.

Program umożliwia zarządzanie strukturą drzewa, wykonywanie operacji na jego elementach oraz zapisywanie i odczytywanie danych z plików tekstowych i binarnych.

## Funkcjonalności

- Dodawanie elementów do drzewa BST.
- Usuwanie wybranego elementu.
- Usuwanie całego drzewa.
- Wyszukiwanie elementu i wyświetlanie drogi do niego.
- Wyświetlanie drzewa w kolejności:
  - Preorder,
  - Inorder,
  - Postorder.
- Graficzne wyświetlanie struktury drzewa w konsoli.
- Zapis drzewa do pliku tekstowego.
- Zapis drzewa do pliku binarnego.
- Odczyt drzewa z pliku binarnego.
- Wczytywanie danych z pliku tekstowego do pustego lub istniejącego drzewa.
- Interaktywne menu konsolowe.

## Wykorzystane technologie

- **Język programowania:** C++
- **Standard:** C++17
- **Struktura danych:** Binary Search Tree (BST)
- **Obsługa plików:** TXT oraz BIN
- **System kontroli wersji:** Git
- **Repozytorium:** GitHub

## Struktura projektu

```text
PZ_Projekt_Drzewo/
│
├── BST.h
├── BST.cpp
│
├── Node.h
├── Node.cpp
│
├── FileManager.h
├── FileManager.cpp
│
├── main.cpp
│
├── dane.txt
│
└── README.md
```

## Kompilacja i uruchomienie

Do kompilacji wymagany jest kompilator obsługujący standard C++17, np. GCC.

### Kompilacja

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp BST.cpp Node.cpp FileManager.cpp -o bst
```

### Uruchomienie

```bash
./bst
```

Po uruchomieniu programu wyświetlane jest menu umożliwiające wybór dostępnych operacji. Po wykonaniu każdej operacji program oczekuje na naciśnięcie klawisza ENTER przed ponownym wyświetleniem menu.

## Autorzy

- Piotr Majchrzak
- Kamil Kwiczal

## Repozytorium GitHub

[https://github.com/p-majchrzak/PZ_Projekt_Drzewo](https://github.com/p-majchrzak/PZ_Projekt_Drzewo)
