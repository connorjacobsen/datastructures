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
queue.pop(); // 42

// queue size
queue.size(); // 5

// is empty?
queue.empty(); // true

// peek at front of queue
queue.front(); // 42

// peek at back of queue
queue.back(); // 17
```