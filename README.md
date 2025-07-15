# data-structures-week-implementation
This Repo is for the Tasks of the First Week in Training 1 with OppoTrain

# Code Editor Used
Visual Studio 2022

# Description of Each Data Structure 
1-Dynamic Arrays
- It is a data structure that can do everything that a static array can do, from set to get etc, but the main difference is that it can shrink or grow size as needed during runtime automatically.
-------------------
2-Singly Linked List
- It is a data structure, represent a sequence nodes that hold data these nodes point to the next node in the list, it only uses a single pointer to do that.
-------------------
3-Stack
- It is a one-ended linear data structure which models a real-world stack by having two primary operations, namely push and pop, it works primary on the principle of LIFO( Last in, First out).
-------------------
4-Queue
- A queue is a linear data structure which models real world queues by having two primary operations, namely enqueue and dequeue, it works primary on the principle of FIFO( First in, First out).
-------------------
5-Doubly Linked List
- It is a data structure, represent a sequence nodes that hold data these nodes point to the next and previous nodes in the list, it uses 2 pointers to do that.
-------------------
6-Circular Linked List
- It is a data structure that contains a sequence of nodes, where each node has data, and points to the next node, additionally and what makes it special from a normal linked list is that the last node points to the first node making the list circular.
-------------------
To be Continued

# Time/ Space Complexity Analysis 
1-Dynamic Arrays
Time Complexity:
- Access-> O(1)
- Search-> O(n)
- Insertion-> O(n)
- Appending-> O(1)
- Deletion-> O(n)

Space Complexity:
Always O(n)

-------------------
2-Singly Linked List and Doubly Linked Lists
Time Complexity:
- Search-> O(n)
- Insert at Head-> O(1)
- Inster at Tail-> O(1)
- Deletion-> O(1)

Space Complexity:
Always O(n)

-------------------
3-Stack
Time Complexity:
- Pushing-> O(1)
- Popping-> O(1)
- Peeking-> O(1)
- Searching-> O(n)
- Size ->O(1)

Space Complexity:
Always O(n)

-------------------
4-Queue for both array and linked list
Time Complexity:
- Enqueue-> O(1)
- Dequeue-> O(1)
- Peek-> O(1)
- IsEmpty-> O(1)
- Size-> O(1)

Space Complexity for both array and linked list:
O(n)

-------------------
5-Circular Linked List
Time Complexity:
- Inserting-> O(1)
- removeFirst-> O(1)
- removeLast-> O(n)
- Appending-> O(1)
- Deletion-> O(1)

Space Complexity:
Always O(n)

-------------------
To be Continued

# Usage Examples
1-Dynamic Arrays
- Assume A is an array [34,4], we can do A.add(-7) during run time and it will add -7 to the array and make it grow automatically.
- Assume A is as array [34,4,-4], we can do A.remove(-4) during run time and it will remove -4 from the array and make it shrink automatically.
- Arrays can be used to implement other data structures such as stacks and lists
-------------------
2-Singly Linked List
- Used in many List, Queue, and Stack implementations.
- Great for creating circular lists.
- Can easily model real-world objects such as trains.
- Used in separate chaining, which is present in certain Hashtable implementations to deal with hashing collisions.
- Often used in the implementation of adjacency lists for graphs.
-------------------
3-Stack
- Used by undo mechanisms in text editors.
- Used in compiler syntax checking for matching brackets and braces.
- Can be used to model a pile of books or plates ( Tower of Hanoi).
- Used behind the scenes to support recursion by keeping track of previous function calls.
- Can be used to do a Depth First Search (DFS) on a graph.
-------------------
4-Queue
- Any waiting line models a queue, for example a lineup at a movie theatre.
- Can be used to efficiently keep track of the x most recently added elements.
- Web server request management where you want first come first serve.
- Breadth First Search (BFS) graph traversal.
-------------------
5-Doubly Linked List
- Undo/Redo functionality.
- Manage a video or music playlist.
- Task Scheduling in OS.
- Implement Double Ended Queues (Deques).
-------------------
6-Circular Linked List
- CPU Scheduling.
- Music and video list Loops
- Multiplier board games such as Monopoly and UNO.
-------------------
To be Continued

# How to Run Tests
For all of the data structures you will need :
- A C++ compiler and a code editor (e.g., Visual Studio 2022).
- Run the code provided in `main()`. All methods of the classes are tested there.
-------------------
1-Dynamic Arrays
- The test code initializes a dynamic Array and performs various operations such as:
  - `add()`
  - `removeAt()`
  - `set()`
  - `clear()`
  and more
- There is also a method called `toString()` that prints the contents of the Dynamic Arrays to visualize the current state of the Dynamic Arrays.
-------------------
2-Singly Linked List
- The test code initializes a Singly Linked List and performs various operations such as:
  - `add()`
  - `get()`
  - `set()`
  - `clear()`
  and more
- There is also a method called `toString()` that prints the contents of the Singly Linked List using to visualize the current state of the Singly Linked List.
-------------------
3-Stack
- The test code initializes a Stack using an array and a linked list and performs various operations in both cases such as:
  - `push()`
  - `pop()`
  - `peek()`
  - `size()`
  and more
- There is also a method called `toString()` that prints the contents of the Stack to visualize the current state of the Stack.
-------------------
4-Queue using array and linked list
The two test codes initialize a Quese using an array and a linked list, and they both performs various operations such as:
  - `enqueue()`
  - `dequeue()`
  - `peek()`
  - `queuesize()`
  and more
- There is also a method called `toString()` that prints the contents of the Queue using array and linked list to visualize the current state of the Queue.
-------------------
5-Doubly Linked List
- The test code initializes a Doubly Linked List and performs various operations such as:
  - `addFirst()`
  - `addLast()`
  - `add()`
  - `peekFirst()`
  - `peekLast()`
  and more
- There is also a method called `toString()` that prints the contents of the Doubly Linked List to visualize the current state of the Doubly Linked List.
  -------------------
5-Circular Linked List
- The test code initializes a Circular Linked List List and performs various operations such as:
  - `add()`
  - `remove()`
  - `addFirst()`
  - `removeFirst()`
  and more
- There is also a method called `printList()` that prints the contents of the Circular Linked List to visualize the current state of the Circular Linked List.
-------------------
To be Continued

