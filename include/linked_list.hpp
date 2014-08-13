#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "linked_list_node.hpp"

template <typename T>
class LinkedList
{
public:
  // pointer to the head of the list
  LinkedListNode<T>* head;

  LinkedList();

  /** METHODS **/

  // Returns true if the list is empty, false otherwise.
  bool empty();

  // Returns the length of the LinkedList.
  unsigned int length();

  // Add value to the head of the linked list.
  void prepend( T value );

  // Add value to the end of the linked list.
  void append( T value );

  // Inserts value at given index. If the index is out of range,
  // inserts value at the tail of the list.
  void insertAt( T value, unsigned int index );

  // Remove the node at the head of the list.
  //
  // PRECONDITION: List must not be empty.
  T decapitate();

  // Remove the node at the end of the list.
  //
  // PRECONDITION: List must not be empty.
  T decaudate();

  // Remove the node at the index.
  //
  // Removes the last item in the list if the index is out of bounds.
  //
  // TODO: Raise exception if index out of bounds.
  T removeAt( unsigned int index );

  // Returns true if the list contains the value.
  // Returns false if the list does not contain the value.
  bool contains( T value );

  // Returns the index of the value if it exists in the list.
  // Returns -1 if value is not in the list.
  //
  // Zero indexed.
  unsigned int indexOf( T value );

  // Returns the value at the head of the list.
  //
  // PRECONDITION: List must not be empty.
  T itemAtHead();

  // Returns the value at the tail of the list.
  //
  // PRECONDITION: List must not be empty.
  T itemAtTail();

  // Returns the value at the given index. If the index is out of bounds,
  // returns the item at the tail of the list.
  //
  // PRECONDITION: Index must be in-bounds for proper function.
  //
  // TODO: Add exception handling for index out of bounds.
  T itemAtIndex( unsigned int index );
};

#include "../src/linked_list.cpp"

#endif // _LINKED_LIST_HPP_
