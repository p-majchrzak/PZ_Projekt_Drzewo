#include "BST.h"
#include <iostream>

/**
 * @brief Konstruktor domyślny klasy BST.
 * Tworzy puste drzewo, ustawiając wskaźnik na korzeń na nullptr.
 */
BST::BST() {
    root = nullptr;
}

/**
 * @brief Destruktor klasy BST.
 * Usuwa całe drzewo z pamięci za pomocą metody clear().
 */
BST::~BST() {
    clear();
}

/**
 * @brief Publiczna metoda wstawiająca nową wartość do drzewa BST.
 * @param value Wartość typu int do wstawienia.
 */
void BST::insert(int value) {
    root = insertRecursive(root, value);
}

/**
 * @brief Prywatna, rekurencyjna metoda pomocnicza wstawiająca wartość do poddrzewa.
 * @param node Wskaźnik na aktualnie rozważany węzeł.
 * @param value Wartość typu int do wstawienia.
 * @return Node* Wskaźnik na zmodyfikowany węzeł.
 */
Node* BST::insertRecursive(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

/**
 * @brief Znajduje węzeł o najmniejszej wartości w poddrzewie.
 * @param node Wskaźnik na korzeń poddrzewa, w którym szukamy minimum.
 * @return Node* Wskaźnik na węzeł z najmniejszą wartością.
 */
Node* BST::findMin(Node* node) {
    Node* current = node;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

/**
 * @brief Publiczna metoda usuwająca węzeł o zadanej wartości z drzewa.
 * @param value Wartość typu int do usunięcia.
 */
void BST::remove(int value) {
    root = removeRecursive(root, value);
}

/**
 * @brief Prywatna, rekurencyjna metoda pomocnicza usuwająca węzeł z poddrzewa.
 * @param node Wskaźnik na aktualny węzeł.
 * @param value Wartość do usunięcia.
 * @return Node* Wskaźnik na zmodyfikowany węzeł.
 */
Node* BST::removeRecursive(Node* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    }
    else {
        // Węzeł bez lewego dziecka
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Węzeł bez prawego dziecka
        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Węzeł posiada dwoje dzieci
        Node* temp = findMin(node->right);

        node->data = temp->data;

        node->right = removeRecursive(node->right, temp->data);
    }

    return node;
}

/**
 * @brief Usuwa całe drzewo, zwalniając pamięć i ustawiając korzeń na nullptr.
 */
void BST::clear() {
    clearRecursive(root);
    root = nullptr;
}

/**
 * @brief Prywatna, rekurencyjna metoda pomocnicza do usuwania węzłów drzewa.
 * @param node Wskaźnik na usuwany węzeł.
 */
void BST::clearRecursive(Node* node) {
    if (node != nullptr) {
        clearRecursive(node->left);
        clearRecursive(node->right);

        delete node;
    }
}

/**
 * @brief Wyszukuje drogę od korzenia do podanej wartości i wypisuje ją na standardowe wyjście.
 * @param value Szukana wartość typu int.
 */
void BST::findPath(int value) {
    Node* current = root;

    std::cout << "Droga do elementu " << value << ": ";

    while (current != nullptr) {
        std::cout << current->data;

        if (current->data == value) {
            std::cout << " - Znaleziono!\n";
            return;
        }

        std::cout << " -> ";

        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    std::cout << "Brak elementu w drzewie.\n";
}

/**
 * @brief Wyświetla elementy drzewa w porządku pre-order (Korzeń - Lewe - Prawe).
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::printPreOrder(Node* node) {
    if (node == nullptr) return;

    std::cout << node->data << " ";

    printPreOrder(node->left);
    printPreOrder(node->right);
}

/**
 * @brief Wyświetla elementy drzewa w porządku in-order (Lewe - Korzeń - Prawe).
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::printInOrder(Node* node) {
    if (node == nullptr) return;

    printInOrder(node->left);

    std::cout << node->data << " ";

    printInOrder(node->right);
}

/**
 * @brief Wyświetla elementy drzewa w porządku post-order (Lewe - Prawe - Korzeń).
 * @param node Wskaźnik na aktualny węzeł.
 */
void BST::printPostOrder(Node* node) {
    if (node == nullptr) return;

    printPostOrder(node->left);
    printPostOrder(node->right);

    std::cout << node->data << " ";
}

/**
 * @brief Pozwala użytkownikowi wybrać metodę przechodzenia drzewa i wyświetla jego zawartość.
 */
void BST::displayTree() {
    int choice;

    std::cout << "\nWybierz metode wyswietlania drzewa:\n";
    std::cout << "1. Pre-order (Korzen - Lewe - Prawe)\n";
    std::cout << "2. In-order (Lewe - Korzen - Prawe)\n";
    std::cout << "3. Post-order (Lewe - Prawe - Korzen)\n";
    std::cout << "Wybierz opcje: ";

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Nieprawidlowe dane.\n";
        return;
    }

    std::cout << "Zawartosc drzewa: ";

    switch (choice) {
        case 1:
            printPreOrder(root);
            break;

        case 2:
            printInOrder(root);
            break;

        case 3:
            printPostOrder(root);
            break;

        default:
            std::cout << "Nieprawidlowy wybor.";
    }

    std::cout << "\n";
}

/**
 * @brief Pomocnicza metoda do graficznego, tekstowego wyświetlania drzewa obróconego o 90 stopni.
 * @param node Wskaźnik na aktualny węzeł.
 * @param depth Aktualna głębokość zagnieżdżenia (używana do wcięć).
 */
void BST::printGraphic(Node* node, int depth) {
    if (node == nullptr) return;

    printGraphic(node->right, depth + 1);

    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }

    std::cout << node->data << "\n";

    printGraphic(node->left, depth + 1);
}

/**
 * @brief Publiczna metoda inicjująca graficzne wyświetlanie drzewa.
 */
void BST::displayGraphic() {
    if (root == nullptr) {
        std::cout << "Drzewo jest puste.\n";
        return;
    }

    std::cout << "\nGraficzna postac drzewa:\n";

    printGraphic(root, 0);
}