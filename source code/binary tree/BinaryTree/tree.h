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

	void Insertion(const T &value);

	bool Search(const T& value, Vertex*& found);

	void Display();

	void Remove(const T& value);
	void Remove(Vertex* removeThis);

private:
	std::vector<Vertex*> vertices;

	Vertex* root;

	Vertex* previous;

	bool condition;

	void RecursiveInsertion(Vertex*& current, const T& value);
	void RecursiveSearch(Vertex*& current, const T& value, Vertex*& found);
	void RecursiveDisplay(Vertex*& current);
	void RecursiveRemove(Vertex*& current, const T& value);
	void RecursiveRemove(Vertex*& current, Vertex* removeThis);

	void Destruct();
	void RecursiveDestruct(Vertex*& current);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	previous = nullptr;
	condition = false;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	Destruct();
}

template <typename T>
void BinaryTree<T>::Insertion(const T& value)
{
	RecursiveInsertion(root, value);
}

template <typename T>
void BinaryTree<T>::RecursiveInsertion(Vertex*& current, const T& value)
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
bool BinaryTree<T>::Search(const T& value, Vertex*& found)
{
	condition = false;
	RecursiveSearch(root, value, found);
	if (!condition)
	{
		std::cout << "The requested value was not found." << std::endl;
		found = nullptr;
	}
	return condition;
}

template <typename T>
void BinaryTree<T>::RecursiveSearch(Vertex*& current, const T& value, Vertex*& found)
{
	if (current != nullptr)
	{
		if (current->data == value)
		{
			condition = true;
			found = current;
		}
		else
		{
			RecursiveSearch(current->left, value, found);
			RecursiveSearch(current->right, value, found);
		}
	}
}

template <typename T>
void BinaryTree<T>::Remove(const T& value)
{
	previous = nullptr;
	RecursiveRemove(root, value);
}

template <typename T>
void BinaryTree<T>::Remove(Vertex* removeThis)
{
	previous = nullptr;
	RecursiveRemove(root, removeThis);
}

template <typename T>
void BinaryTree<T>::RecursiveRemove(Vertex*& current, const T& value)
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
void BinaryTree<T>::RecursiveRemove(Vertex*& current, Vertex* removeThis)
{
	if (current != nullptr)
	{
		if (current == removeThis)
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
					if (removeThis->data > previous->data)
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
					if (previous->data > removeThis->data)
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
					if (previous->data > removeThis->data)
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
				while (replacement->left != nullptr)
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

			RecursiveRemove(current->left, removeThis->data);
			RecursiveRemove(current->right, removeThis->data);
		}
	}
}

template <typename T>
void BinaryTree<T>::Destruct()
{
	if (root != nullptr)
	{
		RecursiveDestruct(root->left);
		RecursiveDestruct(root->right);

		delete root;
	}
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