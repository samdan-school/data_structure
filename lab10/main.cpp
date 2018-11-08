#include "./binary_tree.cpp"

#include <iostream>
using namespace std;

int main() {
    Binary_tree bs = Binary_tree(5);

    bs.insert_node(10);

    std::cout << bs.root->value << ", " << bs.root->right_child->value;

    return 0;
}