#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class BST;
class Node;

/**
 * @brief Klasa odpowiedzialna za obsluge plikow.
 */
class FileManager {
private:
    static bool writeNode(std::ostream& file, const Node* node);
    static Node* readNode(std::istream& file, bool& valid);

public:
    // Pliki tekstowe

    static bool saveText(
        const BST& tree,
        const std::string& filename
    );

    static bool loadText(
        BST& tree,
        const std::string& filename,
        bool clearFirst
    );

    // Pliki binarne

    static bool saveBinary(
        const BST& tree,
        const std::string& filename
    );

    static bool loadBinary(
        BST& tree,
        const std::string& filename
    );
};

#endif