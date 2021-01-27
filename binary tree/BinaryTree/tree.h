#pragma once
#include <vector>

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

	void RecursiveInsertion(Vertex*& current, T& value);

private:
	std::vector<Vertex*> vertices;

	Vertex* root;


};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
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
