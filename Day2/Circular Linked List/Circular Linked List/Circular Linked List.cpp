#include <iostream>//for cin and cout
#include <string>//for string function

using namespace std;

//circular linked list implementation

//node class 
template <typename T>
class Node {
public:
	T data;//data in the node
	Node<T>* next;//pointer to the next node in the list

	//constructor
	Node(T data = 0, Node<T>* next = nullptr)//set default values for thedayta and pointers
	{
		this->data = data;//make the node data = the passed data
		this->next = next;

	}
};

//circular linked list class
template <typename T>
class CircularLinkedList {
private:
	int size;//refer to the number of nodes in the list
	Node<T>* tail;//pointer to the last node in the list

public:

	//constructor 
	CircularLinkedList() {
		size = 0;//set the size to zero when the list is first created
		tail = nullptr;//make the tail point to nothing since the list is empty
	}

	//destructor
	~CircularLinkedList() {
		clear();
	}

	//add an element to the end of the list
	void add(T e) {
		Node<T>* node = new Node<T>(e);//create a new node with the required value
		if (tail == nullptr) {
			tail = node;
			tail->next = tail;
		}//if the list is empty add make the tail point to the node, and make it point to it self refering that there is no other node in the list
		else {
			node->next = tail->next;//update the next pointer of the new node to point to the first added node in the list
			tail->next = node;//make the last node in the list point to the new node
			tail = node;//malke the new node the tail of the list
		}
		size++;//update the size add 1 to it
	}

	//add node to the begining of the list
	void addFirst(T e) {
		Node<T>* node = new Node<T>(e);//create a new node with the required value
		if (tail == nullptr) {
			tail = node;
			tail->next = tail;
		}//if the list is empty add make the tail point to the node, and make it point to it self refering that there is no other node in the list
		else {
			node->next = tail->next;//update the next pointer of the new node to point to the first added node in the list
			tail->next = node;//make the last node in the list point to the new node
		}
		size++;//update the size add 1 to it

	}

	//remove node from the begining of the list
	T removeFirst() {
		if (tail == nullptr)
			return T();//if the list is empty return the default value of the node since you can't remove anything

		T value = tail->next->data;//store the value of the node you want to delete
		if (tail->next == tail) {
			delete tail;
			tail = nullptr;
		}//check if there is only one node in the list, if so delete it and set the tail to null
		else {
			Node<T>*temp = tail->next;//pointer that points to the first node in the list
			tail->next = temp->next;//make the tail point to the new first node in the list
			temp->next = nullptr;//update the node ment to be deleted, make it point to nothing to avoid data leakage
			delete temp;

		}//there is more than one node in the list

		size--;//reduce the size by one 
		return value;//return the value of the node deleted
	}

	//remove the last node in the list
	T removeLast() {
		if (tail == nullptr)
			return T();//if the list is empty return the default value of the node since you can't remove anything

		Node<T>* temp = tail->next;
		if (tail->next == tail) {
			T value = tail->data;//store the value of the node you want to delete
			tail->next = nullptr;//update the node ment to be deleted, make it point to nothing to avoid data leakage
			delete tail;//delete node
			size--;//reduce the size by one
			return value;//return the value of the deleted node
		}
		while (temp->next != tail) {
			temp = temp->next;
		}//trverse the pointer until it points to the node before the tail
		
		T value = tail->data;//store the value of the node you want to delete
		tail = temp;//set the tail top the new last node
		temp = temp->next->next;//set the temp to the first node in the lsit
		tail->next->next = nullptr;//set the next pointer of the node you want to delete to null to avoid leakage
		delete tail->next;//delete the node to avoid leakage
		tail->next = temp;//make the new tail point to first node
		size--;//reduce the size by one
		return value;//return the value of the deleted node

	}


	//check if a specific element exists in the list
	bool contains(T e) {
		if (tail == nullptr)
			return false;//if the list is empty return the default value of the node since you can't remove anything

		Node<T>* temp = tail->next;//point to the first node in the list

		//used do while to ckeck the first element and move to the second element in the first iteration,keep going until we are at the last node

		do{
			if (temp->data == e) {
				return true;
			}
			temp = temp->next;
		} while (temp != tail->next);//if do while not used and used while , the loop will end right of the bit, or some other code logic must change to make it work

			return false;//meaning list traversed and elemenet not found
	}

	//print the entire list
	void printList() {
		if (tail == nullptr) {
			cout << "[ ]" << endl;
			return;
		}//when list is empty print []
		Node<T>* temp = tail->next;//pointer to first element on the list
		cout << "[";
		do {
			cout << temp->data;
			if (!(temp == tail))
				cout << ", ";
			temp = temp->next;
		} while (temp != tail->next);
			
		cout << "]" << endl;
			
	}

	//clear the list 
	void clear() {
		while (tail != nullptr)
			removeFirst();
	}//loop through the whole list and remove all the nodes insude until it is empty

	//get the size of the list
	int getSize() {
		return size;
	}

	//check if the list is empty
	bool isEmpty() {
		return size == 0;
	}

};

int main() {
	CircularLinkedList<int> cll;

	cout << "Initial list: ";
	cll.printList();

	//add elements
	cll.add(10);
	cll.add(20);
	cll.addFirst(5);
	cll.add(30);

	cout << "After adding 5 (first), 10, 20, 30: ";
	cll.printList();

	//remove first and last
	cout << "Removed first: " << cll.removeFirst() << endl;
	cout << "Removed last: " << cll.removeLast() << endl;
	cout << "List after removals: ";
	cll.printList();

	//check contains
	cout << "Contains 10? " << (cll.contains(10) ? "Yes" : "No") << endl;
	cout << "Contains 100? " << (cll.contains(100) ? "Yes" : "No") << endl;

	//get size
	cout << "Current size: " << cll.getSize() << endl;

	//clear and check again
	cll.clear();
	cout << "After clearing: ";
	cll.printList();
	cout << "Is empty? " << (cll.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}

