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

	Vertex* previous;

	void RecursiveInsertion(Vertex*& current, T& value);
	void RecursiveSearch(Vertex*& current, T& value);
	void RecursiveDisplay(Vertex*& current);
	void RecursiveRemove(Vertex*& current, T& value);

	void Destruct();
	void RecursiveDestruct(Vertex*& current);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	previous = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	Destruct();
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
		current->data = value;
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
	std::cout << "the root is " << root->data << std::endl;
	RecursiveDisplay(root);
}

template <typename T>
void BinaryTree<T>::RecursiveDisplay(Vertex*& current)
{
	if (current != nullptr)
	{
		T x = -1;
		T y = -1;

		if (current->left != nullptr)
		{
			x = current->left->data;
		}

		if (current->right != nullptr)
		{
			y = current->right->data;
		}

		std::cout<< x << " < " << current->data << " > " << y <<std::endl;
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
	previous = nullptr;
	RecursiveRemove(root, value);
}

template <typename T>
void BinaryTree<T>::RecursiveRemove(Vertex*& current, T& value)
{
	if (current != nullptr)
	{
		if (current->data == value)
		{
			int validPointers = 0;
			if (current->right != nullptr)
			{
				validPointers++;
			}
			if (current->left != nullptr)
			{
				validPointers++;
			}
			switch (validPointers)
			{
				case 0:
				{
					if (previous != nullptr)
					{
						if (value > previous->data)
						{
							previous->right = nullptr;
						}
						else
						{
							previous->left = nullptr;
						}
					}
					delete current;
				}
				break;
				case 1:
				{
					if (current->left != nullptr)
					{
						if (previous->data > value)
						{
							previous->left = current->left;
						}
						else
						{
							previous->right = current->left;
						}
					}
					else if (current->right != nullptr)
					{
						if (previous->data > value)
						{
							previous->left = current->right;
						}
						else
						{
							previous->right = current->right;
						}
					}
				}
				break;
				case 2:
				{
					Vertex* replacement = current->right;
					while (replacement-> left != nullptr)
					{
						replacement = replacement->left;
					}

						T holdThis = replacement->data;
						Remove(holdThis);
						current->data = holdThis;
				}
				break;
			}
		}
		else
		{
			if (current->left != nullptr || current->right != nullptr)
			{
				previous = current;
			}
			
			RecursiveRemove(current->left, value);
			RecursiveRemove(current->right, value);
		}
	}
}

template <typename T>
void BinaryTree<T>::Destruct()
{
	RecursiveDestruct(root->left);
	RecursiveDestruct(root->right);

	delete root;
}
template <typename T>
void BinaryTree<T>::RecursiveDestruct(Vertex*& current)
{
	if (current != nullptr)
	{
		RecursiveDestruct(current->left);
		RecursiveDestruct(current->right);
		
		delete current;
	}
}