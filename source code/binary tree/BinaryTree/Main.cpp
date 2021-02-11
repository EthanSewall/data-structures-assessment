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
	BinaryTree<int>::Vertex* found;
	theTree.Search(h, found);

	std::cout << "inserting 2, 11, 5, 10 to the tree" << std::endl;

	int a = 2;
	int b = 11;
	int c = 5;
	int d = 10;

	theTree.Insertion(a);
	theTree.Insertion(b);
	theTree.Insertion(c);
	theTree.Insertion(d);

	theTree.Display();

	std::cout << "removing 10" << std::endl;

	int e = 10;
	theTree.Remove(e);

	theTree.Display();
	
	std::cout << "removing 1" << std::endl;

	int f = 1;
	theTree.Remove(f);

	theTree.Display();
	
	std::cout << "removing 7" << std::endl;

	int g = 7;
	theTree.Remove(g);

	theTree.Display();

	char abc = '\0';

	std::cin >> abc;

	return 1;
}