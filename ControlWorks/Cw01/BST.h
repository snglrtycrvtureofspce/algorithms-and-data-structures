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
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    Node* searchHelper(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return searchHelper(node->left, value);
        }
        return searchHelper(node->right, value);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void printTreeHelper(Node* node, int level, char branch) {
        if (node == nullptr) return;

        printTreeHelper(node->right, level + 1, '/');

        for (int i = 0; i < level; i++) std::cout << "   ";
        std::cout << branch << "--" << node->data << std::endl;

        printTreeHelper(node->left, level + 1, '\\');
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    bool search(int value) {
        return searchHelper(root, value) != nullptr;
    }

    void inorderTraversal() {
        std::cout << "Symmetrical (inorder) tree traversal: ";
        inorder(root);
        std::cout << std::endl;
    }

    void printTree() {
        printTreeHelper(root, 0, ' ');
        std::cout << std::endl;
    }
};
