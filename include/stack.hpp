#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <vector>

template <typename T> 
class Stack
{
public:
  /** DATA MEMBERS **/
  std::vector<T> storage; // empty vector

  /** CONSTRUCTORS **/
  Stack();

  /** CLASS METHODS **/

  // Public: Returns the integer size of the Stack.
  unsigned int size();

  // Public: Returns true if the stack is empty, false otherwise.
  bool empty();

  // Public: Return the value at the top of the Stack.
  T top();

  // Public: Add an element to the Stack.
  void push( T element );

  // Public: Remove an element from the Stack and return its value.
  T pop();
};

// include the cpp file so the compiler can see the entire template as
// a single file.
#include "../src/stack.cpp"

#endif // _STACK_HPP_
