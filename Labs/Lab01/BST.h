#pragma once
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) { // идет влево если число меньше
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    Node* findMin(Node* node) { // минимальное в правом поддереве
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteHelper(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = deleteHelper(node->left, value); // идет слева
        }
        else if (value > node->data) {
            node->right = deleteHelper(node->right, value); // идет справа
        }
        else { // найден узел
            if (node->left == nullptr && node->right == nullptr) { // он без детей
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) { // один правый ребенок
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) { // один левый ребенок
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // когда два ребенка
            Node* minNode = findMin(node->right);
            node->data = minNode->data; // заменяет его из найджеенгго
            node->right = deleteHelper(node->right, minNode->data); // удаляет минимальный узел
        }
        return node;
    }

    Node* searchHelper(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) { // если менььше влево
            return searchHelper(node->left, value);
        }
        return searchHelper(node->right, value); // если больше вправо
    }

    // обходы деревва
    void preorder(Node* node) { // прямой (сверху внтз. сначала родитель, потом левое поддерево, потом правое.)
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) { // симметричный (сначала левое поддерево, потом родитель, потом правое. Даёт числа в порядке возрастания.)
        if (node != nullptr) {
            inorder(node->left); // левое поддерево
            std::cout << node->data << " "; // родитель
            inorder(node->right); // правое поддерево
        }
    }

    void postorder(Node* node) { // обратный (снизу вверх. сначала левое поддерево, потом правое, потом родитель.)
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->data << " ";
        }
    }

    void printTreeHelper(Node* node, int level, char branch) {
        if (node == nullptr) return;

        printTreeHelper(node->right, level + 1, '/'); // Правое поддерево

        for (int i = 0; i < level; i++) std::cout << "   ";
        std::cout << branch << "--" << node->data << std::endl; // Узел

        printTreeHelper(node->left, level + 1, '\\'); // Левое поддерево
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void remove(int value) {
        root = deleteHelper(root, value);
    }

    bool search(int value) {
        return searchHelper(root, value) != nullptr;
    }

    void preorderTraversal() {
        std::cout << "Preorder traversal: ";
        preorder(root);
        std::cout << std::endl;
    }

    void inorderTraversal() {
        std::cout << "Inorder traversal: ";
        inorder(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        std::cout << "Postorder traversal: ";
        postorder(root);
        std::cout << std::endl;
    }

    void printTree() {
        std::cout << "Tree structure:\n";
        printTreeHelper(root, 0, ' ');
        std::cout << std::endl;
    }
};