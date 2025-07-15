#include <iostream>//for cin and cout 
#include <string>//to implement string functions

using namespace std;

//array queue implementation
template <typename T>
class ArrayQueue {
private:
	T* array;//pointer to the array (queue)
	int size;//have the current max size of the queue
	int front;//have indix of the first element in the queue
	int rear;//have index of the next insertion position
	int count;//have the current size of the queue

	//update the size of the queue when the array is full to a new given size
	void resize(int newSize) {
		T* newArray = new T[newSize];//new queue with new size
		for (int i = 0;i < count;i++) {
			newArray[i] = array[(front+i)%size];
		}//copying old queue elements (only the ones considered in the queue not the whole array) and addding them to the new queue

		delete[] array;//delete old queue to avoid memory leakage
		array = newArray;//point the original queue to the new queue
		size = newSize;//upddate the size of queue to be the new size
		front = 0;//set the front to be at indix zero because no elements are removed from the queue
		rear = count;//set back to be at count because no elements are added to the queue yet
		
	}

public:

	//default constructor 
	ArrayQueue() {
		size = 10;
		array=new T[size];
		front = 0;
		rear = 0;
		count = 0;
	}

	//destructor
	~ArrayQueue() {
		delete[] array;
	}

	//enqueue an element (add it to the back of the queue)
	void enqueue(T e) {
		if (count == size) {
			resize(size * 2);
		}//check if there is space in the queue

		array[rear] = e;//insert the new element
		rear = (rear + 1) % size;//update the rear position, we id % size so it does not get out of bounds of size
		count++;//update the number of elements

	}

	//dequeue an element (remove it from the front of the queue), and return the element
	T dequeue() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, You Can't Dequeue" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing to dequeue

		T value = array[front];
		front = (front + 1) % size;//update front 
		count--;
		return value;
	}

	//check if queue is empty
	bool isEmpty() {
		return count == 0;
	}

	//peek at the element on the front of the queue without removing it
	T peek() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, Nothing to Peek at" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing to peek at

		return array[front];
	}

	//return the current size of the queue 
	int queuesize() {
		return count;
	}

	//clear the queue and consider it empty without deleting the array
	void clear() {
		count = 0;
		rear = 0;
		front = 0;
	}

	//check if the queue contains a specific required element
	bool contains(T e) {
		if (isEmpty()) {
			cout << "Your Queue is Empty" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing return

		for (int i = 0;i < count;i++) {
			if (array[(front + i) % size] == e)
				return true;
		}//loop through the queue start from front not from 0 because front is not always in the 0 position

		return false;
	}

	//remove the first occurance of a given element
	bool remove(T e) {
		int index = -1;
		for (int i = 0;i < count;i++) {
			if (array[(front + i) % size] == e) {
				index = (front + i) % size;
				break;
			}
		}//loop through the queue and find the index of the element

		if (index == -1)
			return false;
		//return false if the element is not found 

		for (int i = index; i != (rear - 1 + size) % size; i = (i + 1) % size) {
			array[i] = array[(i + 1) % size];
		}//shift elements and fill the gap left by the removed element

		count--;//update count
		rear = (rear - 1 + size) % size;
		return true;//element was found and removed
	}

	//return a string visualisation of the queue 
	//same function implemented in all other data structures
	string toString() {
		if (isEmpty()) return "[]";
		string result = "[";
		for (int i = 0; i < count; i++) {
			result += to_string(array[(front + i) % size]);
			if (i != count - 1)
				result += ", ";
		}
		result += "]";
		return result;
	}


};

int main() {
	ArrayQueue<int> q;

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
	cout << "Contains 99? " << (q.contains(99) ? "Yes" : "No") << endl;

	//remove a value
	cout << "Remove 20: " << (q.remove(20) ? "Removed" : "Not Found") << endl;
	cout << "Queue after removing 20: " << q.toString() << endl;

	//queue size
	cout << "Queue size: " << q.queuesize() << endl;

	//clear queue
	q.clear();
	cout << "Queue after clear: " << q.toString() << endl;
	cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}
