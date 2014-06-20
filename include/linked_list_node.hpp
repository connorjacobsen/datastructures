#ifndef _LINKED_LIST_NODE_HPP_
#define _LINKED_LIST_NODE_HPP_

template <typename T>
class LinkedListNode
{
public:
	T data;
	LinkedListNode* next;

	LinkedListNode() { next = nullptr; }
	explicit LinkedListNode( T value ) { 
		data = value;
		next = nullptr;
	}
};

#endif // _LINKED_LIST_NODE_HPP_