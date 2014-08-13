#include "../include/queue.hpp"

template <typename T>
Queue<T>::Queue() {}

template <typename T>
void Queue<T>::push( T element )
{
  storage.push_back( element );
}

template <typename T>
T Queue<T>::pop()
{
  T element = storage.front();
  storage.erase( storage.begin() );
  return element;
}

template <typename T>
unsigned int Queue<T>::size()
{
  return storage.size();
}

template <typename T>
bool Queue<T>::empty()
{
  return storage.empty();
}

template <typename T>
T Queue<T>::front()
{
  return storage.front();
}

template <typename T>
T Queue<T>::back()
{
  return storage.back();
}
