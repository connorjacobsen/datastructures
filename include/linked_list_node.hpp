#ifndef _LINKED_LIST_NODE_HPP_
#define _LINKED_LIST_NODE_HPP_

template <typename T>
class LinkedListNode
{
public:
  T data;
  LinkedListNode* next;

  LinkedListNode();
  explicit LinkedListNode( T value );
};

#include "../src/linked_list_node.cpp"

#endif // _LINKED_LIST_NODE_HPP_
