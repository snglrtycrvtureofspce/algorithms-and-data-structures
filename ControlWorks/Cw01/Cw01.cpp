#include <iostream>
#include <vector>
#include <sstream>
#include "BST.h"

int main() {
    BST tree;
    std::vector<int> numbers;
    std::string input;
    bool valid = false;

    std::cout << "Are the numbers entered manually (m) or automatically (a)? ";
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (input == "a") {
        numbers = { 50, 56, 320, 23, 49, 40, 22, 15, 25, 35, 45 };
    }
    else {
        std::cout << "Enter 10 to 15 integers separated by a space:\n";
        while (!valid) {
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int num;
            numbers.clear();

            while (iss >> num) {
                numbers.push_back(num);
            }

            if (numbers.size() >= 10 && numbers.size() <= 15) {
                valid = true;
            }
            else {
                std::cout << "Error: you need 10 to 15 **whole** numbers. Repeat:\n";
            }
        }
    }

    std::cout << "\nInserting numbers into the tree:\n";
    for (int n : numbers) {
        std::cout << n << " ";
        tree.insert(n);
    }
    std::cout << "\n\nTree structure:\n";
    tree.printTree();

    tree.inorderTraversal();

    int value;
    std::cout << "\nEnter the value to search for: ";
    std::cin >> value;
    std::cout << (tree.search(value) ? "Found" : "Not found") << std::endl;

    std::cout << "Enter the value to be inserted: ";
    std::cin >> value;
    tree.insert(value);
    tree.printTree();
    tree.inorderTraversal();

    return 0;
}