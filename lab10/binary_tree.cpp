#if !defined(BINARY_TREE_CPP)
#define BINARY_TREE_CPP
#include <algorithm>
#include <iostream>
using namespace std;

class node {
   public:
    int value;
    node *left_child;
    node *right_child;
    int height;

    node() {
        value = 0;
        left_child = nullptr;
        right_child = nullptr;
        height = 0;
    }

    node(int value) {
        this->value = value;
        left_child = nullptr;
        right_child = nullptr;
        height = 0;
    }
};

class Binary_tree {
   public:
    node *root;

    Binary_tree(int value) {
        root = new node(value);
    }

    void insert(int value) {
        this->root = insert(this->root, value);
    }

    node *insert(node *current, int value) {
        if (current == nullptr) {
            current = new node(value);
        } else if (current->value > value) {
            current->left_child = insert(current->left_child, value);

            if (height(current->left_child) - height(current->right_child) == 2) {
                cout << "CUR VALUE: " << current->value << endl;
                if (height(current->left_child->left_child) > height(current->left_child->right_child)) {
                    cout << "L L OVER" << endl;
                } else {
                    cout << "L R OVER" << endl;
                }
            }
        } else if (current->value < value) {
            current->right_child = insert(current->right_child, value);

            if (height(current->right_child) - height(current->left_child) == 2) {
                cout << "CUR VALUE: " << current->value << endl;
                if (height(current->right_child->left_child) > height(current->right_child->right_child)) {
                    cout << "R L OVER" << endl;
                } else {
                    cout << "R R OVER" << endl;
                }
            }
        }

        current->height = height(current);
        return current;
    }

    int height(node *start) {
        if (start == nullptr)
            return 0;

        int l = 0, r = 0;

        if (start->left_child) {
            l = height(start->left_child);
        }
        if (start->right_child) {
            r = height(start->right_child);
        }

        return 1 + max(l, r);
    }

    node *search_node(int value) {
        node *current = root;
    }

    void print_tree(node *start, int depth = 0) {
        cout << "DEPTH: " << depth << " - VALUE: " << start->value << " - HEIGHT: " << start->height << endl;
        if (start->left_child)
            print_tree(start->left_child, depth + 1);
        if (start->right_child)
            print_tree(start->right_child, depth + 1);
    }

    void delete_node(node *start) {
        if (start->left_child)
            delete_node(start->left_child);
        if (start->right_child)
            delete_node(start->right_child);
        // cout << "DEST: " << start->value << endl;
        delete start;
    }

    ~Binary_tree() {
        // cout << endl;
        delete_node(this->root);
    }
};

#endif  // BINARY_TREE_CPP
