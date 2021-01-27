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

private:
	std::vector<Vertex*> vertices;

	Vertex* root;


};
