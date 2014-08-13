#include "../include/linked_list_node.hpp"

template <typename T>
LinkedListNode<T>::LinkedListNode()
{
  next = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode( T value )
{
  data = value;
  next = nullptr;
}
