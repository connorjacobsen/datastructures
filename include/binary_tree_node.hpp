#ifndef _BINARY_TREE_NODE_HPP_
#define _BINARY_TREE_NODE_HPP_

template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode* leftChild;
	BinaryTreeNode* rightChild;

	BinaryTreeNode() 
	{
		leftChild  = nullptr;
		rightChild = nullptr;
	}

	BinaryTreeNode( T data ) : data(data)
	{
		leftChild  = nullptr;
		rightChild = nullptr;
	}
};

#endif // _BINARY_TREE_NODE_HPP_