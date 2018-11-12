#include "./binary_tree.cpp"

#include <iostream>
using namespace std;

int main() {
    Binary_tree bs = Binary_tree(10);

    bs.insert(9);
    bs.insert(15);
    bs.insert(13);
    bs.insert(17);
    bs.insert(14);
    // bs.insert(12);
    // bs.rec_insert(bs.root, 12);
    // bs.rec_insert(bs.root, 20);

    bs.print_tree(bs.root);

    if (bs.search_node(-1)) {
        cout << "VALUE DOES EXISTS!" << endl;
    } else {
        cout << "VALUE DOES NOT EXISTS!" << endl;
    }

    return 0;
}