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

    Binary_tree(int value) { root = new node(value); }

    void insert(int value) { this->root = insert(this->root, value); }

    node *left_left_swap(node *current) {
        node *left_child = current->left_child;
        current->left_child = left_child->right_child;
        left_child->right_child = current;

        return left_child;
    }

    node *left_right_swap(node *current) {
        node *left_child_s_right_child = current->left_child->right_child;
        current->left_child->right_child = left_child_s_right_child->left_child;
        left_child_s_right_child->left_child = current->left_child;
        current->left_child = left_child_s_right_child;

        return left_child_s_right_child;
    }

    node *right_right_swap(node *current) {
        node *right_child = current->right_child;
        current->right_child = right_child->left_child;
        right_child->left_child = current;

        return right_child;
    }

    node *right_left_swap(node *current) {
        node *right_child_s_left_child = current->right_child->left_child;
        current->right_child->left_child =
            right_child_s_left_child->right_child;
        right_child_s_left_child->right_child = current->right_child;
        current->right_child = right_child_s_left_child;

        return right_child_s_left_child;
    }

    node *insert(node *current, int value) {
        if (current == nullptr) {
            current = new node(value);
        } else if (current->value > value) {
            current->left_child = insert(current->left_child, value);

            if (height(current->left_child) - height(current->right_child) ==
                2) {
                cout << "CUR VALUE: " << current->value << endl;
                if (height(current->left_child->left_child) >
                    height(current->left_child->right_child)) {
                    cout << "L L OVER" << endl;
                    current = left_left_swap(current);
                } else {
                    cout << "L R OVER" << endl;
                    left_right_swap(current);
                    current = left_left_swap(current);
                }
            }
        } else if (current->value < value) {
            current->right_child = insert(current->right_child, value);

            if (height(current->right_child) - height(current->left_child) ==
                2) {
                cout << "CUR VALUE: " << current->value << endl;
                if (height(current->right_child->right_child) >
                    height(current->right_child->left_child)) {
                    cout << "R R OVER" << endl;
                    current = right_right_swap(current);
                } else {
                    cout << "R L OVER" << endl;
                    right_left_swap(current);
                    current = right_right_swap(current);
                }
            }
        }

        current->height = height(current);
        return current;
    }

    int height(node *start) {
        if (start == nullptr) return 0;

        int l = 0, r = 0;

        if (start->left_child) {
            l = height(start->left_child);
        }
        if (start->right_child) {
            r = height(start->right_child);
        }

        return 1 + max(l, r);
    }

    node *search_node(node *start, int value) {
        node *current = start;

        if (current == nullptr) {
            return nullptr;
        } else if (current->value == value) {
            return current;
        } else if (current->value > value) {
            search_node(current->left_child, value);
        } else if (current->value < value) {
            search_node(current->right_child, value);
        }
    }

    bool search_node(int value) {
        if (search_node(this->root, value) != nullptr)
            return true;
        else
            return false;
    }

    void print_tree(node *start, int depth = 0) {
        cout << "DEPTH: " << depth << " - VALUE: " << start->value
             << " - HEIGHT: " << height(start) << endl;
        if (start->left_child) print_tree(start->left_child, depth + 1);
        if (start->right_child) print_tree(start->right_child, depth + 1);
    }

    void delete_node(node *start) {
        if (start->left_child) delete_node(start->left_child);
        if (start->right_child) delete_node(start->right_child);
        // cout << "DEST: " << start->value << endl;
        delete start;
    }

    ~Binary_tree() {
        // cout << endl;
        delete_node(this->root);
    }
};

#endif  // BINARY_TREE_CPP