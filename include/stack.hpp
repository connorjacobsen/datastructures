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
	Stack() {}

	/** CLASS METHODS **/

	// Public: Returns the integer size of the Stack.
	unsigned int size()
	{
		return storage.size();
	}

	// Public: Returns true if the stack is empty, false otherwise.
	bool empty()
	{
		return storage.empty();
	}

	// Public: Return the value at the top of the Stack.
	T top()
	{
		T element = storage.back();
		return element;
	}

	// Public: Add an element to the Stack.
	void push( T element )
	{
		storage.push_back( element );
	}

	// Public: Remove an element from the Stack and return its value.
	T pop()
	{
		T element = storage.back();
		storage.pop_back();
		return element;
	}
};

#endif