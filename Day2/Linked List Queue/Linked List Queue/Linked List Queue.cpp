#include <iostream>//for cin and cout
#include <string>//to use string functions

using namespace std;

//linked list queue implementation

//node class for each element in the queue
template <typename T>
class Node {
public:

	T data;
	Node<T>* next;

	//constructor for the node with a given value
	Node(T value) {
		this->data = value;
		next = nullptr;
	}

};

//actual linked list (queue)
template  <typename T>
class LinkedListQueue {
private:
	Node<T>* front;//pointer to the front of the queue
	Node<T>* rear;//pointer to the back of the queue
	int length;//current size of the queue

public:
	//default constructor
	LinkedListQueue() {
		front = nullptr;
		rear = nullptr;
		length = 0;
	}//since the queue is empty all pointers are set to null and the length will be 0

	//destructor
	~LinkedListQueue() {
		clear();
	}

	//add an element at the end of the queue
	void enqueue(T e) {
		Node<T>* node = new Node<T>(e);//create the new node
		if (isEmpty()) {
			front = rear = node;
		}//if the queue is empty add the node to the queue and point to it with both front and rear 
		else {
			rear->next = node;
			rear = node;
		}//if the queue is not empty add the node at the end of the queue and upddate the rear pointer position

		length++;
	}

	//remove the oldest node in the queue
	T dequeue() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, You Can't Dequeue" << endl;
			return T();
		}//check if the queue is empty
		
		T value = front->data;//store the value to return 
		Node<T>* temp = front;//temp pointer to delete the node when done
		front = front->next;//update the first position to be at the second latest node
		if (!front)
			rear = nullptr;//meaning the queue is now empty and we reset everything to default
		delete temp;//delete the node to avoid memory leakage
		length--;//reduce the length by 1
		return value;//return the removed value
		
	}

	//check if the queue is empty
	bool isEmpty() {
		return length == 0;
	}

	//peek at the first element in the queue
	T peek() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, Nothing to Peek at" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing to peek a

		return front->data;
	}

	//return the size of the queue
	int queuesize() {
		return length;
	}

	//clear the queue remve and dellocate everything
	void clear() {
		while (!isEmpty())
			dequeue();//if queue is not empty keep dequeuing until it is 
	}

	//check if the queue contains a given value
	bool contains(T e) {
		if (isEmpty()) {
			cout << "Your Queue is Empty" << endl;
			return false;
		}//return default value when the queue is empty and the is nothing return

		Node<T>* temp = front;//add a pointer at the begining of the queue to trverse through it
		while (temp) {
			if (temp->data == e)
				return true;
			temp = temp->next;
		}//keep looping until either the element is found or you have traversed through the whole queue

		return false;//no element is found so return false
	}

	//remove a given element from the queue
	bool remove(T e) {
		if (isEmpty())
			return false;//check if the queue is empty
		Node<T>* temp1 = front;
		Node<T>* temp2 = nullptr;
		while(temp1){
			//case 1 the node is the first node and there is only one node in the queue
			if(temp1->data==e){
				if (temp2 == nullptr) {
					front = front->next;
					if (front == nullptr) {
						rear = nullptr;
					}

				}
				//case 2 
				else {
					temp2->next = temp1->next;//move temp2 pointer 
					if (temp1 == rear)//if the node was the last node and we found the element
						temp2 = rear;
				}
				delete temp1;//delete the node
				length--;//reduce the length
				return true;//return true meaning it was found
			}

			//update the pointers and keep traversing through until the element is found
			temp2 = temp1;
			temp1 = temp1->next;
		}
		//if the element is not found return false
		return false;

	}

	//return a string visualisation of the queue 
	//same function implemented in all other data structures
	string toString() {
		if (isEmpty()) return "[]";

		string result = "[";
		Node<T>* current = front;
		while (current) {
			result += to_string(current->data);
			if (current->next) result += ", ";
			current = current->next;
		}
		result += "]";
		return result;
	}
};

int main() {
	LinkedListQueue<int> q;

	//enqueue some elements
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout << "Queue after enqueue 10, 20, 30: " << q.toString() << endl;

	//dequeue
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Queue after one dequeue: " << q.toString() << endl;

	//peek
	cout << "Peek: " << q.peek() << endl;

	//contains
	cout << "Contains 20? " << (q.contains(20) ? "Yes" : "No") << endl;
	cout << "Contains 50? " << (q.contains(50) ? "Yes" : "No") << endl;

	//remove a value
	cout << "Remove 30: " << (q.remove(30) ? "Removed" : "Not Found") << endl;
	cout << "Queue after removing 30: " << q.toString() << endl;

	//queue size
	cout << "Current size: " << q.queuesize() << endl;

	//clear queue
	q.clear();
	cout << "After clearing: " << q.toString() << endl;
	cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;


	return 0;
}



