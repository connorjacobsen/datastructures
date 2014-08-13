#include "../include/stack.hpp"

template <typename T>
Stack<T>::Stack() {}

template <typename T>
unsigned int Stack<T>::size()
{
  return storage.size();
}

template <typename T>
bool Stack<T>::empty()
{
  return storage.empty();
}

template <typename T>
T Stack<T>::top()
{
  T element = storage.back();
  return element;
}

template <typename T>
void Stack<T>::push( T element )
{
  storage.push_back( element );
}

template <typename T>
T Stack<T>::pop()
{
  T element = storage.back();
  storage.pop_back();
  return element;
}
