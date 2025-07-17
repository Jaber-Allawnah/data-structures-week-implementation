#include <iostream>//for cin and cout

using namespace std;
//min heap implementation

//min heap class
template <typename T>
class MinHeap {
private:
	T* heap;//pointer to array to store the values
	int capacity;//store the max capacity the heap can hold
	int size;//store the current size of the heap

	//restor the min heap property after a new element is added to the heap
	void heapifyUp(int index) {
		while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
			swap(heap[index], heap[(index - 1) / 2]);//when the child is smaller than the parent then swap them using the swap func
			index = (index - 1) / 2;
		}//loop while the index is valid, and the current element is smaller than it's parent
	}

	//restor the min heap property after an element is removed to the heap
	void heapifyDown(int index) {
		int smallest = index;//the position where the last element in the heap is now adddedd
		int left = 2 * index + 1;//the left child of the smallest
		int right = 2 * index + 2;//the right child of the smallest

		if (left < size && heap[left] < heap[smallest]) {
			smallest = left;
		}//left child is smaller than the new root

		if (right < size && heap[right] < heap[smallest]) {
			smallest = right;
		}//right child is smaller than the new root 

		if (smallest != index) {
			swap(heap[index], heap[smallest]);
			heapifyDown(smallest);
		}//check for the new smallest, if the children and smaller or not
	}

	//when the heap is full, double the size 
	void resize() {
		T* newHeap = new T[capacity * 2];//make a new heap
		for (int i = 0;i < size;i++) {
			newHeap[i] = heap[i];
		}//copy all the elements to the new heap

		delete[] heap;//remvoe the old heap to prevent leakge
		heap = newHeap;//make the original pointer point to the ne wheap
		capacity = capacity * 2;//update the size of the heap

	}

public:

	//constructor
	MinHeap() {
		capacity = 10;//default value
		size = 0;//no current elements in the heap
		heap = new T[capacity];//make the heap
	}

	//destructor
	~MinHeap() {
		delete[] heap;
	}//just delete the array to avoid memeory leakage

	//inset and element to the heap
	void insert(T value) {
		if (size == capacity) {
			resize();
		}//check if the heap is full or not

		heap[size] = value;//add element at the end
		//heap may lose the heap propert to we do hepifyup
		heapifyUp(size);//it willcompare the new element with the parent until it is in place
		size++;//update the size of the heap

	}

	//get the min value in the heap (root)
	T getMin() {
		if (size == 0) {
			cout << "Heap is empty!\n";
			return T();//return the default value
		}//check if the heap is empty

		return heap[0];
	}

	//remove from the heap and heapify because it may lose the heap property
	void remove() {
		if (size == 0) {
			cout << "Heap is empty!\n";
			return;
		}//check if the heap is empty

		heap[0] = heap[size - 1];//set the new root to be the latest added element
		size--;//will make the old root appear to be removed but it is still there
		heapifyDown(0);

	}

	//display the heap content
	void printHeap() {
		for (int i = 0;i < size;i++) {
			cout << heap[i] << " ";
		}
		cout << endl;

	}


};

int main() {
	MinHeap<int> h;

	//insert elements to heap
	h.insert(25);
	h.insert(17);
	h.insert(36);
	h.insert(2);
	h.insert(3);
	h.insert(100);
	h.insert(1);

	cout << "Heap elements after insertions: ";
	h.printHeap();

	//get minimum element from heap
	cout << "Minimum element: " << h.getMin() << endl;

	//remove minimum element from heap
	h.remove();
	cout << "Heap after removing min: ";
	h.printHeap();

	//remove again from heap
	h.remove();
	cout << "Heap after removing min again: ";
	h.printHeap();

	//insert another element to the heap
	h.insert(0);
	cout << "Heap after inserting 0: ";
	h.printHeap();

	return 0;
}
