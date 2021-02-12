#pragma once
#include <iostream>

template <typename T>
class DoubleLinkedList
{
	struct node
	{
		T data;
		node* next;
		node* previous;
	};



	node* front;
	node* end;

public:

	struct iterator
	{
		node* current;

	public:
		iterator(node* Node)
		{
			current = Node;
		}

		T data()
		{
			return current->data;
		}
		iterator operator++()
		{
			if (current->next != nullptr)
			{
				current = current.next;
			}
		}
		iterator operator--()
		{
			if (current->previous != nullptr)
			{
				current = current.previous;
			}
		}
	};

	DoubleLinkedList();

	~DoubleLinkedList();

	DoubleLinkedList<T>::iterator start()
	{
		auto it = new iterator(front);
		return *it;
	}

	DoubleLinkedList<T>::iterator finish()
	{
		auto it = new iterator(end);
		return *it;
	}

	void pushFront(const T& value);

	void pushEnd(const T& value);

	void popFront();

	void popEnd();

	T& getFront();

	T& getEnd();

	void display();

	void remove(const T& value);

	bool empty();

	void clear();

	void resize(int size);
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	front = nullptr;
	end = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	node* current = front;
	node* deletion = nullptr;

	while (current != nullptr)
	{
		deletion = current->next;
		delete current;
		current = deletion;
	}
}

template <typename T>
void DoubleLinkedList<T>::pushFront(const T& value)
{
	node* newNode = new node();
	newNode->data = value;
	newNode->previous = nullptr;
	newNode->next = front;


	if (front != nullptr)
	{
		front->previous = newNode;
		front = newNode;
	}
	else
	{
		front = newNode;
	}

	if (end == nullptr)
	{
		end = newNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::pushEnd(const T& value)
{
	node* newNode = new node();
	newNode->data = value;
	newNode->previous = end;
	newNode->next = nullptr;

	if (end != nullptr)
	{
		end->next = newNode;
		end = newNode;
	}
	else
	{
		end = newNode;
	}

	if (front == nullptr)
	{
		front = newNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::popFront()
{
	node* oldFront = front;

	front = oldFront->next;

	if (front != nullptr)
	{
		front->previous = nullptr;
	}
	else
	{
		end = nullptr;
	}

	delete oldFront;
}

template <typename T>
void DoubleLinkedList<T>::popEnd()
{
	node* oldEnd = end;

	end = oldEnd->previous;

	if (end != nullptr)
	{
		end->next = nullptr;
	}
	else
	{
		front = nullptr;
	}

	delete oldEnd;
}

template <typename T>
T& DoubleLinkedList<T>::getFront()
{
	return front->data;
}

template <typename T>
T& DoubleLinkedList<T>::getEnd()
{
	return end->data;
}

template <typename T>
void DoubleLinkedList<T>::display()
{
	node* current = front;
	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

template <typename T>
void DoubleLinkedList<T>::remove(const T& value)
{
	node* current = front;
	node* holdThis = nullptr;
	while (current != nullptr)
	{
		if (current->data == value)
		{
			holdThis = current;

			if (current->previous != nullptr)
			{
				current->previous->next = current->next;
			}
			if (current->next != nullptr)
			{
				current->next->previous = current->previous;
			}

			holdThis = current->next;
			delete current;
			current = holdThis;
		}
		else
		{
			current = current->next;
		}
		
	}
}

template <typename T>
void DoubleLinkedList<T>::clear()
{
	while (front != nullptr)
	{
		popFront();
	}
}

template <typename T>
bool DoubleLinkedList<T>::empty()
{
	if (front == nullptr && end == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void DoubleLinkedList<T>::resize(int value)
{
	int i = 0;
	node* current = front;
	bool longer = false;

	for (; i < value+1; i++)
	{
		if (current == nullptr)
		{
			longer = true;
			pushEnd(0);
			current = end;
		}
		else
		{
			current = current->next;
		}
	}
	if (!longer)
	{
		while (current-> next != nullptr)
		{
			i++;
			if (current->next != nullptr)
			{
				current = current->next;
			}
		}

		current = end;
		node* holdThis = current->previous;
		while (i+1 > value)
		{
			popEnd();
			i--;
		}
	}
	
}

