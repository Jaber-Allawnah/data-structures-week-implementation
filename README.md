# data-structures-week-implementation
This Repo is for the Tasks of the First Week in Training 1 with OppoTrain

# Code Editor Used
Visual Studio 2022

# Description of Each Data Structure 
1-Dynamic Arrays
- It is a data structure that can do everything that a static array can do, from set to get etc, but the main difference is that it can shrink or grow size as needed during runtime automatically.
-------------------
2-Singly Linked List
- It is a data structure, represent a sequence nodes that hold data which point to the next node also containing data using a single pointer for each node.
-------------------
3-Stack
- It is a one-ended linear data structure which models a real-world stack by having two primary operations, namely push and pop, and workd primary on the principle of LIFO( Last in, First out)
-------------------
To be continued

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
2-Singly Linked List
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
To be continued

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
To be continued

# How to Run Tests
For all of the data structures you will need :
- A C++ compiler and a code editor (e.g., Visual Studio 2022).
- Run the code provided in `main()`. All methods of the classes are tested there.
-------------------
1-Dynamic Arrays
- The test code initializes a dynamic array and performs various operations such as:
  - `add()`
  - `removeAt()`
  - `set()`
  - `clear()`
  and more
- It also prints the contents of the array using the `toString()` function to visualize the current state of the array.
-------------------
2-Singly Linked List
- The test code initializes a Singly Linked List and performs various operations such as:
  - `add()`
  - `get()`
  - `set()`
  - `clear()`
  and more
- It also prints the contents of the Singly Linked List using the `toString()` function to visualize the current state of the Singly Linked List.
-------------------
3-Stack
- The test code initializes a Stack using an array and a linked list and performs various operations in both cases such as:
  - `push()`
  - `pop()`
  - `peek()`
  - `size()`
  and more
- They also print the contents of the Stack using the `toString()` function to visualize the current state of the Stack.
-------------------
To be continued
