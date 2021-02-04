#include "tree.h"

int main()
{
	BinaryTree<int> theTree;

	int x = 3;
	int y = 7;
	int z = 1;

	theTree.Insertion(x);
	theTree.Insertion(y);
	theTree.Insertion(z);

	theTree.Display();

	return 1;
}