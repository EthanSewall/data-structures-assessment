#pragma once
#pragma once

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

	DoubleLinkedList()
	{
		front = nullptr;
		end = nullptr;
	}

	~DoubleLinkedList()
	{

	}

	void pushFront(const T& value);

	void pushEnd(const T& value);

	void popFront();

	void popEnd();

	T& front();

	T& end();
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
		front->prev = newNode;
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
		front->prev = nullptr;
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
T& DoubleLinkedList<T>::front()
{
	return front->data;
}

template <typename T>
T& DoubleLinkedList<T>::end()
{
	return end->data;
}

