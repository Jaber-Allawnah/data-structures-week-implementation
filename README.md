# data-structures-week-implementation
This Repo is for the Tasks of the First Week in Training 1 with OppoTrain

# Code Editor Used
Visual Studio 2022

# Description of Each Data Structure 
1-Dynamic Arrays
- It is a data structure that can do everything that a static array can do, from set to get etc, but the main difference is that it can shrink or grow size as needed during runtime automatically.
  <img width="596" height="270" alt="dynamic array" src="https://github.com/user-attachments/assets/45d6deb0-2067-4d28-865e-7bf41847e0a6" />
  
-------------------
2-Singly Linked List
- It is a data structure, represent a sequence nodes that hold data these nodes point to the next node in the list, it only uses a single pointer to do that.
  <img width="716" height="254" alt="singly-linkedlist" src="https://github.com/user-attachments/assets/6e663d43-67b0-4a97-ab27-23113a2db9cd" />
  
-------------------
3-Stack
- It is a one-ended linear data structure which models a real-world stack by having two primary operations, namely push and pop, it works primary on the principle of LIFO( Last in, First out).
<img width="512" height="366" alt="stack" src="https://github.com/user-attachments/assets/43f6b402-fec5-4dc7-95f3-de5d1610e3d3" />

-------------------
4-Queue
- A queue is a linear data structure which models real world queues by having two primary operations, namely enqueue and dequeue, it works primary on the principle of FIFO( First in, First out).
 <img width="544" height="353" alt="queue" src="https://github.com/user-attachments/assets/a762074e-b1c3-4980-86d8-0ba2be40c40b" />
 
-------------------
5-Doubly Linked List
- It is a data structure, represent a sequence nodes that hold data these nodes point to the next and previous nodes in the list, it uses 2 pointers to do that.
 <img width="933" height="176" alt="DLL" src="https://github.com/user-attachments/assets/45478a1a-1948-4ecf-a450-404d0f13f349" />
 
-------------------
6-Circular Linked List
- It is a data structure that contains a sequence of nodes, where each node has data, and points to the next node, additionally and what makes it special from a normal linked list is that the last node points to the first node making the list circular.
  <img width="944" height="153" alt="CLL" src="https://github.com/user-attachments/assets/8482d830-6d6a-4b57-b267-bdc86204ede2" />
  
-------------------
7-Binary Tree
- A binary tree is a directed acyclic graph (made from n nodes and n-1 edges), for which every node has at most two child nodes.
  <img width="941" height="605" alt="image" src="https://github.com/user-attachments/assets/d3f34d53-07b4-4b35-ba93-b5b1c3e0ae26" />
  
-------------------
8-Binary Search Tree (BST)
- A binary search tree is a binary tree that satisfies the BST invariant, where the left subtree has smaller elements than the root and right subtree has larger elements than the root.
 <img width="734" height="342" alt="BST" src="https://github.com/user-attachments/assets/e6d6be69-e007-4dd9-8709-8e9eb880dd92" />
 
-------------------
9-Hash Table
- HTs are often used to track item frequencies. For instance, counting the number of times a word appears in a given text.
  <img width="892" height="435" alt="Hash Table" src="https://github.com/user-attachments/assets/ad40636d-937a-4c03-954a-1844058cd747" />
  
-------------------
10-Min Heap
- A min heap is a special case of a binary tree, where it is a complete tree except for possibly the leafes, the parent node should be <= the child nodes.
  <img width="257" height="304" alt="Min hEap 1" src="https://github.com/user-attachments/assets/6bc9cb61-f682-487e-ba87-cccb1382c776" />
  
  <img width="292" height="364" alt="Min Heap2" src="https://github.com/user-attachments/assets/b925993b-1b5c-4c8f-909c-4b1e026ef88c" />
  
  <img width="903" height="390" alt="MIn Heap 3" src="https://github.com/user-attachments/assets/28a1caa8-df2c-416d-89ba-84bc7b3e25cc" />
  
-------------------
11-Graph 
- A graph is a data structure that is made of vertices (nodes) and edges (links), it can be directed or undirected, weighted or unweighted, and it is used to represent multiple other data structures.
  <img width="872" height="350" alt="Graph" src="https://github.com/user-attachments/assets/dcb5230e-4a72-45b4-868f-1c8d10574909" />
  
-------------------
12-Trie
- A Trie is a tree data structure, used to store words char by char in a tree in and effcient and space saving way, the path from the root to a node that has an end of word flag is a word.
 <img width="715" height="666" alt="Trie" src="https://github.com/user-attachments/assets/e308cd85-56d9-467f-8f5f-ae7d4cb389e5" />
 
-------------------
13-Unoin Find
- Unoin Find is a data structure that help manage a group of disjoint sets, they are sets that have elements in them but they never overlap.
  <img width="525" height="235" alt="image" src="https://github.com/user-attachments/assets/63988f7f-f9ac-47e8-8c72-2c6c9cf5d5a9" />
  
  <img width="617" height="269" alt="image" src="https://github.com/user-attachments/assets/b9a1e299-6924-4fea-b6c1-0c532709d734" />
  
  <img width="654" height="296" alt="image" src="https://github.com/user-attachments/assets/94361302-a2d3-4b31-9ddb-f5fca1b1359b" />
  
  <img width="681" height="307" alt="image" src="https://github.com/user-attachments/assets/202209e0-cd86-4beb-b40f-04ead59a3099" />
  
-------------------
14-Graph traversal BFS 
- BFS is an uninformed graph traversal algorithm that visits all nodes level by level starting from a given source node, it uses queues to store vistied nodes, dequeue them when they are visited to vist the next node in the queue.
  <img width="1315" height="727" alt="image" src="https://github.com/user-attachments/assets/7693033e-af63-4684-9a53-1a43a78bfaa5" />

-------------------
15-Graph traversal DFS
- DFS is an uninformed graph traversal algorithm that visits all nodes going into the depth of the graph starting from a given source node, it uses stacks to store vistied nodes, pop them when they are visited to vist the next node in the queue.
  <img width="1343" height="765" alt="image" src="https://github.com/user-attachments/assets/55f99226-8191-4af9-bff8-6a3801ef0f0a" />
  
-------------------

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
6-Binary Tree
Time Complexity:
- Insert-> O(n)
- Delete (full tree)-> O(n)
- Remove (one node)-> O(n)
- Search-> O(n)

Space Complexity:
Always O(n)

-------------------
7-Binary Search Tree
Time Complexity:
- Insert-> O(n)
- Delete (full tree)-> O(n)
- Remove (one node)-> O(n)
- Search-> O(n)

Space Complexity:
Always O(n)

-------------------
8-Hash Table
Time Complexity:
- Insert-> O(n)
- Remove-> O(n)
- Search-> O(n)

Space Complexity:
Always O(n)

-------------------
9-Min Heap
Time Complexity:
- Insert-> O(1)
- GetMin-> O(logn)	
- Remove-> O(log n)
- Heapify-> O(logn)	

Space Complexity:
To extract Min and HeapifyO(1)

-------------------
10-Graph using and Adjacency Matrix
Time Complexity:
- O(V^2) where v is the number of verticies

Space Complexity:
Always O(V^2)

-------------------
11-Trie
Time Complexity:
- Insert-> O(n)
- search-> O(n)	
- startsWith-> O(n)	

Space Complexity:
O(N * k)	where k us the 26  alphabets and N is number of characters stored

-------------------
12-Unoin Find
Time Complexity:
- find-> O(n)
- union-> O(n)	

Space Complexity:
O(n)

-------------------
13-Graph traversal BFS 
Time Complexity:
- O(b^s) where b in the number of nodes and s is the level of tree

Space Complexity:
O(b^s)

-------------------
14-Graph traversal DFS
Time Complexity:
- O(b^m) where b in the number of nodes and m is the deepest level

Space Complexity:
O(bm)

-------------------


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
7-Binary Trees
- Used in BST.
- Used in the implementation of binary heaps.
- Syntax trees
- Treap
-------------------
8-Binary Search Trees
- Implementation of some map and set ADTs.
- Red-Black Trees.
- AVL Trees.
- Splay Trees.
-------------------
9-Hash Table
- Key-Value Storage
- Caching
- Routing Tables in networks
- Symbol Tables
-------------------
10-Min Heap
- Priority Queue	
- Dijkstra's Algorithm	
- Heap Sort	
-------------------
11-Graph
- Networks
- Navigation Systems	
- Trees
- Social Networks	
-------------------
12-Trie
- Keyboard suggestions
- IP routing	
- Dictionary storage	
- Word games	
-------------------
13-Unoin Find
- Cycle detection in a graph	
- Merging accounts or sets	
-------------------
14-Graph traversal BFS 
- Shortest path	
- AI agents search
-------------------
15-Graph traversal DFS
- Topological sort	
- AI agents search
-------------------

# How to Run Tests
For all of the data structures you will need :
- A C++ compiler and a code editor (e.g., Visual Studio 2022).
- Open the folder with the name of the data structure you want to test.
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
6-Circular Linked List
- The test code initializes a Circular Linked List and performs various operations such as:
  - `add()`
  - `remove()`
  - `addFirst()`
  - `removeFirst()`
  and more
- There is also a method called `printList()` that prints the contents of the Circular Linked List to visualize the current state of the Circular Linked List.
-------------------
7-Binary Trees
- The test code initializes a Binary Tree and performs various operations such as:
  - `insert()`
  - `size()`
  - `isEmpty()`
  - `clear()`
  and more
- Note that the requirment tree traversal algorithms (inorder, preorder, postorder) is implemented and tested in the code as well in the follownig functions:
  - `preorder()`
  - `inorder()`
  - `postorder()`
------------------- 
8-Binary Search Trees
- The test code initializes a Binary Search Trees and performs various operations such as:
  - `add()`
  - `remove()`
  - `contains()`
  - `height()`
  and more
- Note that the requirment tree traversal algorithms (inorder, preorder, postorder) is implemented and tested in the code as well in the follownig functions:
  - `preorder()`
  - `inorder()`
  - `postorder()`
------------------- 
9-Hash Table
- The test code initializes a Hash Table with collision detection using chaining and adressing and it performs various operations such as:
  - `insert()`
  - `get()`
  - `remove()`
  and more
-------------------
10-Min Heap
- The test code initializes a Min Heap and performs various operations such as:
  - `insert()`
  - `getMin()`
  - `remove()`
  - `heapifyUp()`
  - `heapifyDown()`
  and more
- There is also a method called `printHeap()` that prints the contents of the Min Heap to visualize the current state of the Min Heap.
-------------------
11-Graphs
- The test code initializes a Graphs and performs various operations such as:
  - `addEdge()`
  - `removeEdge()`
  - `clear()`
  - `isEmpty()`
  and more
- There is also a method called `printGraph()` that prints the contents of the Graphs to visualize the current state of the Graphs.
-------------------
12-Trie
- The test code initializes a Trie and performs various operations such as:
  - `insert()`
  - `search()`
  - `startsWith()`
-------------------
13-Unoin Find
- The test code initializes a Unoin Find and performs various operations such as:
  - `find()`
  - `unionSets()`
-------------------
14-Graph traversal BFS 
- The test code initializes a Graph and performs BFS on it using a queue and BFS principle using an opertation called:
  - `bfs()`
-------------------
15-Graph traversal DFS 
- The test code initializes a Graph and performs DFS on it using a stack and DFS principle using an opertation called:
  - `dfs()`
-------------------
