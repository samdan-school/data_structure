#include "./binary_tree.cpp"

#include <iostream>
using namespace std;

int main() {
    Binary_tree bs = Binary_tree(10);

    bs.insert(5);
    bs.insert(13);
    bs.insert(11);
    bs.insert(15);
    bs.insert(12);
    // bs.rec_insert(bs.root, 12);
    // bs.rec_insert(bs.root, 20);

    bs.print_tree(bs.root);

    return 0;
}