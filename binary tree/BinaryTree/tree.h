#pragma once
#include <vector>
#include <iostream>

template <typename T>
class BinaryTree
{
public:
	struct Vertex
	{
		T data;

		Vertex* left;
		
		Vertex* right;
	};

	BinaryTree();
	~BinaryTree();

	void Insertion(T &value);

	void Search(T& value);

	void Display();

	void Remove(T& value);

private:
	std::vector<Vertex*> vertices;

	Vertex* root;

	void RecursiveInsertion(Vertex*& current, T& value);
	void RecursiveSearch(Vertex*& current, T& value);
	void RecursiveDisplay(Vertex*& current);
	void RecursiveRemove(Vertex*& current, T& value);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	previousVertex = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	for each (Vertex v in vertices)
	{
		delete v;
	}
}

template <typename T>
void BinaryTree<T>::Insertion(T& value)
{
	RecursiveInsertion(root, value);
}

template <typename T>
void BinaryTree<T>::RecursiveInsertion(Vertex*& current, T& value)
{
	if (current == nullptr)
	{
		current = new Vertex();
		current->data = T;
		vertices.push_back(current);
	}
	else
	{
		if (current->data == value)
		{
			//ignore this
		}
		else if (value < current->data)
		{
			RecursiveInsertion(current->left, value);
		}
		else
		{
			RecursiveInsertion(current->right, value);
		}
	}
}

template <typename T>
void BinaryTree<T>::Display()
{
	RecursiveDisplay(root);
}

template <typename T>
void BinaryTree<T>::RecursiveDisplay(Vertex*& current)
{
	if (current != nullptr)
	{
		std::cout << current->data << std::endl;
		RecursiveDisplay(current->left);
		RecursiveDisplay(current->right);
	}
}

template <typename T>
void BinaryTree<T>::Search(T& value)
{
	RecursiveSearch(root, value);
}

template <typename T>
void BinaryTree<T>::RecursiveSearch(Vertex*& current, T& value)
{
	if (current != nullptr)
	{
		if (current->data == value)
		{
			std::cout << "the value is at " << &*current << std::endl;
		}
		else
		{
			RecursiveSearch(current->left, value);
			RecursiveSearch(current->right, value);
		}
	}
}

template <typename T>
void BinaryTree<T>::Remove(T& value)
{
	RecursiveRemove(root, value);
}

template <typename T>
void BinaryTree<T>::RecursiveRemove(Vertex*& current, T& value)
{

	if (current != nullptr)
	{
		if (current->left != nullptr)
		{
			if (current->left->data == value)
			{
				if (current->left->left == nullptr && current->left->right == nullptr)
				{
					delete current->left;
					current->left = nullptr;
				}
				else if (current->left->left == nullptr ^ current->left->right == nullptr)
				{
					if (current->left->left == nullptr)
					{
						delete current->left;
						current->left = current->left->right;
					}
					else
					{
						delete current->left;
						current->left = current->left->left;
					}
				}
				else
				{

				}
			}
		}
		else if (current->right != nullptr)
		{
			if (current->right->data == value)
			{

			}
		}
		else
		{
			RecursiveRemove(current->left, value);
			RecursiveRemove(current->right, value);
		}
	}
}
