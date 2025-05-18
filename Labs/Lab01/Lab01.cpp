#include <iostream>
#include "BST.h"

int main() {
    BST tree;
    int numbers[] = { 50, 56, 320, 23, 49, 40, 22, 15, 25, 35, 45, 55, 65, 75, 85 };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Inserting numbers: ";
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
        tree.insert(numbers[i]);
    }
    std::cout << std::endl;

    tree.printTree();
    tree.preorderTraversal();
    tree.inorderTraversal();
    tree.postorderTraversal();

    int searchValue = 40;
    std::cout << "\nSearching for " << searchValue << ": ";
    std::cout << (tree.search(searchValue) ? "Found" : "Not found") << std::endl;

    int deleteValue = 30;
    std::cout << "\nDeleting " << deleteValue << std::endl;
    tree.remove(deleteValue);
    tree.printTree();
    tree.inorderTraversal();

    int insertValue = 33;
    std::cout << "\nInserting " << insertValue << std::endl;
    tree.insert(insertValue);
    tree.printTree();
    tree.inorderTraversal();

    return 0;
}