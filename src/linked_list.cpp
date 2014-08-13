#include "../include/linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
}

template <typename T>
bool LinkedList<T>::empty()
{
  if( head == nullptr )
    return true;
  return false;
}

template <typename T>
unsigned int LinkedList<T>::length()
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

template <typename T>
void LinkedList<T>::prepend( T value )
{
  LinkedListNode<T>* node = new LinkedListNode<T>( value );
  node->next = head;
  head = node;
}

template <typename T>
void LinkedList<T>::append( T value )
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

template <typename T>
void LinkedList<T>::insertAt( T value, unsigned int index )
{
  LinkedListNode<T>* node = head;
  LinkedListNode<T>* tmp = new LinkedListNode<T>( value );
  while( index > 1 && node->next != nullptr ) {
    node = node->next;
    --index;
  }
  tmp->next = node->next;
  node->next = tmp;
}

template <typename T>
T LinkedList<T>::decapitate()
{
  LinkedListNode<T>* node = head;
  head = node->next;
  delete node;
  return node->data;
}

template <typename T>
T LinkedList<T>::decaudate()
{
  // if list has length 1, decapitate the list.
  if( length() == 1 )
    return decapitate();

  // else, decaudate the list.
  LinkedListNode<T>* node = head;
  LinkedListNode<T>* prev = node;
  while( node->next != nullptr ) {
    prev = node;
    node = node->next;
  }
  prev->next = nullptr;
  delete node;
  return node->data;
}

template <typename T>
T LinkedList<T>::removeAt( unsigned int index )
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

template <typename T>
bool LinkedList<T>::contains( T value )
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

template <typename T>
unsigned int LinkedList<T>::indexOf( T value )
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

template <typename T>
T LinkedList<T>::itemAtHead()
{
  LinkedListNode<T>* node = head;
  return node->data;
}

template <typename T>
T LinkedList<T>::itemAtTail()
{
  LinkedListNode<T>* node = head;
  while( node->next != nullptr ) {
    node = node->next;
  }
  return node->data;
}

template <typename T>
T LinkedList<T>::itemAtIndex( unsigned int index )
{
  LinkedListNode<T>* node = head;
  while( index > 0 && node->next != nullptr ) {
    node = node->next;
    --index;
  }
  return node->data;
}
