#include "list.h"
int main()
{
	DoubleLinkedList<int> intList;

	intList.pushFront(78);

	intList.pushFront(87);
	
	intList.pushFront(345);
	
	return 1;
}