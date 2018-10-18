#include "./complete_binary_tree.h"

#define SIZE 7

int main()
{
	int cbtree[SIZE] = {7, 8, 1, 4, 3, 9, 2};

	cout << endl
		 << "ROOT IS: " << endl;
	root(cbtree, SIZE - 1);

	cout << endl
		 << endl
		 << "LEAF IS: " << endl;
	leaf(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "LEVEL IS: " << endl
		 << level(cbtree, SIZE);

	cout << endl
		 << endl
		 << "HEIGHT IS: " << endl
		 << height(cbtree, SIZE);

	cout << endl
		 << endl
		 << "ANCESTOR IS: " << endl;
	ancestor(cbtree, 6, SIZE - 1);

	cout << endl
		 << endl
		 << "DESCENDANT IS: " << endl;
	descendant(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "SIBLINGS IS: " << endl;
	siblings(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "PARENT IS: " << endl;
	parent(cbtree, 4, SIZE - 1);

	cout << endl
		 << endl
		 << "CHILDREN IS: " << endl;
	children(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "PREORDER IS: " << endl;
	preorder(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "INORDER IS: " << endl;
	inorder(cbtree, 0, SIZE - 1);

	cout << endl
		 << endl
		 << "POSTORDER IS: " << endl;
	postorder(cbtree, 0, SIZE - 1);

	return 0;
}