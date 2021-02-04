#include "list.h"
int main()
{
	DoubleLinkedList<int> intList;

	std::cout << "pushing 78, 87, 345 to front. List:" << std::endl;

	intList.pushFront(78);

	intList.pushFront(87);
	
	intList.pushFront(345);

	intList.display();

	std::cout << "pushing 456, 139 to end. List:" << std::endl;

	intList.pushEnd(456);

	intList.pushEnd(139);

	intList.display();

	std::cout << "popping end. List:" << std::endl;

	intList.popEnd();

	intList.display();

	std::cout << "popping front. List:" << std::endl;

	intList.popFront();

	intList.display();
	
	return 1;
}