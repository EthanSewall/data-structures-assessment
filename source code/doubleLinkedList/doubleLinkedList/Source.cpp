#include "list.h"
int main()
{
	DoubleLinkedList<int>* intList = new DoubleLinkedList<int>;

	std::cout << "pushing 78, 87, 345 to front. List:" << std::endl;

	intList->pushFront(78);

	intList->pushFront(87);
	
	intList->pushFront(345);

	intList->display();

	std::cout << "pushing 456, 139 to end. List:" << std::endl;

	intList->pushEnd(456);

	intList->pushEnd(139);

	intList->display();

	std::cout << "popping end. List:" << std::endl;

	intList->popEnd();

	intList->display();

	std::cout << "popping front. List:" << std::endl;

	intList->popFront();

	intList->display();

	std::cout << "removing 78. List:" << std::endl;

	intList->remove(78);

	intList->display();

	std::cout << "resizing: 4. List:" << std::endl;

	intList->resize(4);

	intList->display();

	std::cout << "generating iterator. List:" << std::endl;

	auto iteration = intList->start();
	intList->display();

	std::cout << "Iterator position: " << iteration.data() << std::endl;

	iteration++;

	std::cout << "moving iterator (++). Iterator position: " << iteration.data() << std::endl;

	iteration--;

	std::cout << "moving iterator (--). Iterator position: " << iteration.data() << std::endl;

	std::cout << "" << std::endl;

	std::cout << "resizing: 2. List:" << std::endl;

	intList->resize(2);

	intList->display();

	std::cout << "clearing. List:" << std::endl;

	intList->clear();

	intList->display();

	std::cout << "" << std::endl;
	std::cout << "List.empty: " << intList->empty() << std::endl;

	char abc = '\0';

	std::cin >> abc;
	
	return 1;
}