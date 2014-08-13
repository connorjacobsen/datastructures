#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <vector>

template <typename T>
class Queue
{
public:
  /** DATA MEMBERS **/
  std::vector<T> storage;

  /** CONSTRUCTOR **/
  Queue();

  /** DATA MEMBERS **/

  //  Add an element to the Queue.
  void push( T element );

  // Remove element from the Queue and return its value.
  T pop();

  // Get size of the Queue.
  unsigned int size();

  // Check if the Queue is empty.
  bool empty();

  // Peek at the front of the Queue.
  T front();

  // Peek at the back of the Queue.
  T back();
};

#include "../src/queue.cpp"

#endif // _QUEUE_HPP_
