#if !defined(BINARY_TREE_CPP)
#define BINARY_TREE_CPP
#include <iostream>
using namespace std;

class node {
   public:
    int value;
    node *left_child;
    node *right_child;

    node() {
        value = 0;
        left_child = nullptr;
        right_child = nullptr;
    }

    node(int value) {
        this->value = value;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class Binary_tree {
   public:
    node *root;
    int lenght;

    Binary_tree(int value) {
        root = new node(value);
        lenght = 1;
    }

    void insert_node(int value) {
        node *current = root;

        while (1) {
            if (current->value > value) {
                if (current->left_child) {
                    current = current->left_child;
                } else {
                    current->left_child = new node(value);
                    lenght++;
                    return;
                }
            } else {
                if (current->right_child) {
                    current = current->right_child;
                } else {
                    current->right_child = new node(value);
                    lenght++;
                    return;
                }
            }
        }
    }

    node *search_node(int value) {
        node *current = root;
    }

    int find_level(node *pos) {
        }

    int find_left_level(node *pos) {
        node *current = pos;
        if (current->left_child) {
            return 1 + find_left_level(current->left_child);
        } else {
            return 0;
        }
    }

    int find_right_level(node *pos) {
        node *current = pos;
        if (current->right_child) {
            return 1 + find_right_level(current->right_child);
        } else {
            return 0;
        }
    }
};

#endif  // BINARY_TREE_CPP
