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