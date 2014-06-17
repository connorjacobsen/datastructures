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
	Queue() {}

	/** DATA MEMBERS **/

	//  Add an element to the Queue.
	void push( T element ) { storage.push_back( element ); }

	// Remove element from the Queue and return its value.
	T pop()
	{
		T element = storage.front();
		storage.erase( storage.begin() );
		return element;
	}

	// Get size of the Queue.
	unsigned int size() { return storage.size(); }

	// Check if the Queue is empty.
	bool empty() { return storage.empty(); }

	// Peek at the front of the Queue.
	T front() { return storage.front(); }

	// Peek at the back of the Queue.
	T back() { return storage.back(); }
};

#endif