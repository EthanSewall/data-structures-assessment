#include "tree.h"
#include <iostream>

int main()
{
	BinaryTree<int> theTree;

	int x = 3;
	int y = 7;
	int z = 1;

	theTree.Insertion(x);
	theTree.Insertion(y);
	theTree.Insertion(z);

	std::cout << "inserting 3, 7, 1 to the tree" << std::endl;

	theTree.Display();

	std::cout << "searching for 7" << std::endl;
	int h = 7;
	theTree.Search(h);

	std::cout << "inserting 2, 11, 5 to the tree" << std::endl;

	int a = 2;
	int b = 11;
	int c = 5;

	theTree.Insertion(a);
	theTree.Insertion(b);
	theTree.Insertion(c);

	theTree.Display();

	std::cout << "removing 11" << std::endl;

	int e = 11;
	theTree.Remove(e);

	theTree.Display();

	return 1;
}