#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#ifndef _LINKED_LIST_NODE_HPP
#define _LINKED_LIST_NODE_HPP
#include "linked_list_node.hpp"
#endif // _LINKED_LIST_NODE_HPP

template <typename T>
class LinkedList
{
public:
	// pointer to the head of the list
	LinkedListNode<T>* head;

	LinkedList() { head = nullptr; }

	/** METHODS **/

	// Returns true if the list is empty, false otherwise.
	bool empty()
	{
		if( head == nullptr )
			return true;
		return false;
	}

	// Returns the length of the LinkedList.
	unsigned int length()
	{
		if( empty() )
			return 0;
		LinkedListNode<T>* node = head;
		unsigned int count = 1;
		while( node->next != nullptr ) {
			node = node->next;
			count++;
		}
		return count;
	}

	// Add value to the head of the linked list.
	void prepend( T value )
	{
		LinkedListNode<T>* node = new LinkedListNode<T>( value );
		node->next = head;
		head = node;
	}

	// Add value to the end of the linked list.
	void append( T value )
	{
		LinkedListNode<T>* tmp = new LinkedListNode<T>( value );
		if( empty() ) {
			prepend( value );
		} else {
			LinkedListNode<T>* node = head;
			while( node->next != nullptr ) {
				node = node->next;
			}
			node->next = tmp;
		}
	}

	// Inserts value at given index. If the index is out of range,
	// inserts value at the tail of the list.
	void insertAt( T value, unsigned int index )
	{
		LinkedListNode<T>* node = head;
		LinkedListNode<T>* tmp  = new LinkedListNode<T>( value );
		while( index > 1 && node->next != nullptr ) {
			node = node->next;
			--index;
		}
		tmp->next = node->next;
		node->next = tmp;
	}

	// Remove the node at the head of the list.
	//
	// PRECONDITION: List must not be empty.
	T decapitate()
	{
		// if( empty() )
		// 	return;
		LinkedListNode<T>* node = head;
		head = node->next;
		delete node;
		return node->data;
	}

	// Remove the node at the end of the list.
	//
	// PRECONDITION: List must not be empty.
	T decaudate()
	{
		// if list has length 1, decapitate the list.
		if( length() == 1 )
			return decapitate();

		// else, decaudate the list.
		LinkedListNode<T>* node = head;
		LinkedListNode<T>* prev = node;
		while( node->next != nullptr )
		{
			prev = node;
			node = node->next;
		}
		prev->next = nullptr;
		delete node;
		return node->data;
	}

	// Remove the node at the index.
	//
	// Removes the last item in the list if the index is out of bounds.
	//
	// TODO: Raise exception if index out of bounds.
	T removeAt( unsigned int index )
	{
		LinkedListNode<T>* node = head;
		if( index == 0 ) {
			head = node->next;
			delete node;
			return node->data;
		} else {
			LinkedListNode<T>* prev = head;
			while( index > 0 && node->next != nullptr ) {
				prev = node;
				node = node->next;
				--index;
			}
			prev->next = node->next;
			delete node;
			return node->data;
		}
	}

	// Returns true if the list contains the value.
	// Returns false if the list does not contain the value.
	bool contains( T value )
	{
		LinkedListNode<T>* node = head;
		while( node->next != nullptr ) {
			if( node->data == value )
				return true;
			node = node->next;
		}
		if( node->data == value )
			return true;
		return false;
	}

	// Returns the index of the value if it exists in the list.
	// Returns -1 if value is not in the list.
	//
	// Zero indexed.
	unsigned int indexOf( T value )
	{
		unsigned int index = 0;
		LinkedListNode<T>* node = head;
		while( node->next != nullptr ) {
			if( node->data == value )
				return index;
			node = node->next;
			++index;
		}
		if( node->data == value )
			return index;
		return -1;
	}

	// Returns the value at the head of the list.
	//
	// PRECONDITION: List must not be empty.
	T itemAtHead()
	{
		LinkedListNode<T>* node = head;
		return node->data;
	}

	// Returns the value at the tail of the list.
	//
	// PRECONDITION: List must not be empty.
	T itemAtTail()
	{
		LinkedListNode<T>* node = head;
		while( node->next != nullptr ) {
			node = node->next;
		}
		return node->data;
	}

	// Returns the value at the given index. If the index is out of bounds,
	// returns the item at the tail of the list.
	//
	// PRECONDITION: Index must be in-bounds for proper function.
	//
	// TODO: Add exception handling for index out of bounds.
	T itemAtIndex( unsigned int index )
	{
		LinkedListNode<T>* node = head;
		while( index > 0 && node->next != nullptr ) {
			node = node->next;
			--index;
		}
		return node->data;
	}
};

#endif // _LINKED_LIST_HPP_