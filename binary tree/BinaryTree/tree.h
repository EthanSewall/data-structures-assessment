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

	Vertex* replacement;

	void RecursiveInsertion(Vertex*& current, T& value);
	void RecursiveSearch(Vertex*& current, T& value);
	void RecursiveDisplay(Vertex*& current);
	void RecursiveRemove(Vertex*& current, T& value);

	void FindReplacement(Vertex*& current);
	void RecursiveReplacement(Vertex*& current);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	previousVertex = nullptr;
	replacement = nullptr;
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
	if (root->data == value)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr ^ root->right == nullptr)
		{
			if (root->left == nullptr)
			{
				Vertex* holdThis = root->right;
				delete root;
				root = holdThis;
			}
			else
			{
				Vertex* holdThis = root->left;
				delete root;
				root = holdThis;
			}
		}
		else
		{
			FindReplacement(root);
			root->data = replacement->data;
			root->left = replacement->left;
			root->right = replacement->right;
			delete replacement;
			replacement = nullptr;
		}
	}
	else
	{
		RecursiveRemove(root, value);
	}
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
						Vertex* holdThis = current->left->right;
						delete current->left;
						current->left = holdThis;
					}
					else
					{
						Vertex* holdThis = current->left->left;
						delete current->left;
						current->left = holdThis;
					}
				}
				else
				{
					FindReplacement(current->left);
					current->left->data = replacement->data;
					current->left->left = replacement->left;
					current->left->right = replacement->right;
					delete replacement;
					replacement = nullptr;
				}
			}
		}
		else if (current->right != nullptr)
		{
			if (current->right->data == value)
			{
				if (current->right->left == nullptr && current->right->right == nullptr)
				{
					delete current->right;
					current->right = nullptr;
				}
				else if (current->right->left == nullptr ^ current->right->right == nullptr)
				{
					if (current->right->left == nullptr)
					{
						Vertex* holdThis = current->right->right;
						delete current->right;
						current->right = holdThis;
					}
					else
					{
						Vertex* holdThis = current->right->left;
						delete current->right;
						current->right = holdThis;
					}
				}
				else
				{
					FindReplacement(current->right);
					current->right->data = replacement->data;
					current->right->left = replacement->left;
					current->right->right = replacement->right;
					delete replacement;
					replacement = nullptr;
				}
			}
		}
		else
		{
			RecursiveRemove(current->left, value);
			RecursiveRemove(current->right, value);
		}
	}
}

template <typename T>
void BinaryTree<T>::FindReplacement(Vertex*& current)
{
	if (current->right->left == nullptr)
	{
		replacement = current->right;
	}
	else
	{
		RecursiveReplacement(current->right);
	}
}

template <typename T>
void BinaryTree<T>::RecursiveReplacement(Vertex*& current)
{
	if (current->left == nullptr)
	{
		replacement = current;
	}
	else
	{
		RecursiveReplacement(current->left);
	}
}
