#include "./binary_tree.cpp"

#include <iostream>
using namespace std;

int main() {
    Binary_tree bs = Binary_tree(20);

    bs.insert(10);
    bs.insert(30);
    bs.insert(9);
    bs.insert(40);
    bs.insert(25);
    bs.insert(23);
    // bs.insert(16);
    // bs.insert(12);

    bs.remove(23);

    bs.print_tree(bs.root);

    if (bs.search_node(100)) {
        cout << "VALUE DOES EXISTS!" << endl;
    } else {
        cout << "VALUE DOES NOT EXISTS!" << endl;
    }

    return 0;
}