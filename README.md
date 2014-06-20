# datastructures
Pragmatic C++ data structures library.

### Stack
Public Interface:
```cpp
// create a new stack
Stack<int> stack = Stack<int>();

// push
stack.push( 42 );

// pop
stack.pop(); // returns value

// stack size
stack.size();

// is empty?
stack.empty();

// peek at top of the stack without removing value.
stack.top();
```

### Queue
```cpp
// new queue
Queue<int> queue = Queue<int>();

// push onto queue
queue.push( 42 );

// pop off queue
queue.pop(); // => 42

// queue size
queue.size(); // => 5

// is empty?
queue.empty(); // => true

// peek at front of queue
queue.front(); // => 42

// peek at back of queue
queue.back(); // => 17
```

### LinkedList
```cpp
// new linked list
LinkedList<int> list = LinkedList<int>();

// check if list is empty
list.empty(); // => true

// get size of list
list.length(); // => 5

// prepend value to list
list.prepend( 42 ); 

// append value to list
list.append( 42 );

// insert item at a given index
list.insertAt( 42, 2 );

// remove item at head of list
list.decapitate(); // => 42

// remove item at the end of the list
list.decaudate(); // => 42

// remove item at a given index
list.removeAt( 3 ); // => 42

// get value at head of list
list.itemAtHead(); // => 42

// get value at the tail of the list
list.itemAtTail(); // => 42

// get value at a given index
list.itemAt( 5 ); //  => 42

// check if list contains a value
list.contains( 3 ); // => true

// get index of value in the list
list.indexOf( 3 ); // => 2
```