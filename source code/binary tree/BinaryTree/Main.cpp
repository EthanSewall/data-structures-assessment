#include "tree.h"
#include <iostream>

int main()
{
	BinaryTree<int> theTree;


	theTree.Insertion(3);
	theTree.Insertion(7);
	theTree.Insertion(1);

	std::cout << "inserting 3, 7, 1 to the tree" << std::endl;

	theTree.Display();

	std::cout << "searching for 7" << std::endl;
	BinaryTree<int>::Vertex* found;
	theTree.Search(7, found);

	std::cout << "the value is at " << &*found << std::endl;

	std::cout << "inserting 2, 11, 5, 10 to the tree" << std::endl;

	theTree.Insertion(2);
	theTree.Insertion(11);
	theTree.Insertion(5);
	theTree.Insertion(10);

	theTree.Display();

	std::cout << "removing 10" << std::endl;

	theTree.Remove(10);

	theTree.Display();
	
	std::cout << "removing 1" << std::endl;

	theTree.Remove(1);

	theTree.Display();
	
	std::cout << "removing 7" << std::endl;

	theTree.Remove(found);

	theTree.Display();

	char abc = '\0';

	std::cin >> abc;

	return 1;
}