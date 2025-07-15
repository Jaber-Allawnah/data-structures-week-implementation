#include <iostream>//for cin and cout
#include <string>//for string functions

using namespace std;

//doubly linked list code

//node class
template <typename T>
class Node {
public:
	Node<T>* next;//pointer to the next node
	Node<T>* prev;//pointer to the previous node
	T data;//data inside the node

	//constructor
	Node(Node<T>* next = nullptr, Node<T>* prev = nullptr, T data=0)//set the default values of the pointer to null
	{
		//if there are actual values then we assign them here
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

//doubly linked list class
//followed the java code in the youtube course but made it into c++
template <typename T>
class DoublyLinkedList {
private:
	int size ;//current size of the list
	Node<T>* head ;//pointer to the begining of the list
	Node<T>* tail ;//pointer to the end of the list

	//a function to remove a node from the list
	T remove(Node<T> * node) {
		if (node->prev == nullptr) {
			return removeFirst();//if node is the first node then remove it using this function case 1
		}
		else if (node->next == nullptr) {
			return removeLast();//if node is the last node then remove it using this function case 1
		}
		//case 3 node is not first nor last
		//update the pointers of the nodes before and after the node you want to delete
		else {
			node->next->prev = node->prev;
			node->prev->next = node->next;

			T value = node->data;
			delete node;
			size--;

			return value;
		}

	}

public:
	//default constructor
	DoublyLinkedList() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	//destructor
	~DoublyLinkedList() {
		clear();
	}

	//remove all nodes from the list and clear it
	void clear() {
		Node<T>* temp = head;//pointer to traverse through the whole list
		while (temp != nullptr) {
			Node<T>* next = temp->next;//a pointer to the next node to help traversing and not losing the list
			delete temp;//delete the current node to avoid memory leakage
			temp = next;

		}//keep looping until you have traversed through the whole list

		size = 0;//rest the size to 0 since the list is now empty
		head = nullptr;//set the head to null since it is pointing to nothing
		tail = nullptr;//set the tail to null since it is pointing to nothing

	}

	//return the current size of the list
	int getSize() {
		return size;
	}

	//check if the list is empty
	bool isEmpty() {
		return size == 0;
	}

	//add an element to the end of the list
	void addLast(T e) {

		if(isEmpty()){
			Node<T> *node = new Node<T>(nullptr, nullptr, e);//create a node that has the value you want to add to the list
			head = tail = node;
		}//if the list is empty then make both the head/ tail point to it
		else {
			Node<T> *node = new Node<T>(nullptr, tail, e);//make a node and make it point to the current tail, and have the value required
			tail->next = node;//make the current latest node in the list point to the new node
			tail = tail->next;//update the tail pointer

		}

		size++;//update the size of the list
	}

	//add an element to the start of the list
	void addFirst(T e) {

		if (isEmpty()) {
			Node<T> *node = new Node<T>(nullptr,nullptr,e);//create a node that has the value you want to add to the list
			head = tail = node;
		}//if the list is empty then make both the head/ tail point to it
		else {
			Node<T>* node = new Node<T>(head, nullptr, e);//make a node and make it point to the current tail, and have the value required
			head->prev = node;//make the current first node point to the new node
			head = head->prev;//move the header pointer to the new node
		}

		size++;//update the size of the list and add 1
	}

	//add an element to the list
	void add(T e) {
		addLast(e);//just call the add last function and it will do the job
	}

	//peek at the first item in the list
	T peekFirst() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, Nothing to Peek at" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing to peek a
		
		return head->data;//return the data in the head of the list
	}

	//peek at the last item in the list
	T peekLast() {
		if (isEmpty()) {
			cout << "Your Queue is Empty, Nothing to Peek at" << endl;
			return T();
		}//return default value when the queue is empty and the is nothing to peek a

		return tail->data;//return the data in the tail of the list
	}

	//remove the first element in the list
	T removeFirst() {
		if (isEmpty()) {
			cout << "Your List is Empty, You Can't Remove" << endl;
			return T();
		}//check if the list is empty

		T value = head->data;//set the value of the node delete to return
		Node<T>* temp = head;//a temp pointer to delete the node
		head = head->next;//move the head to the second node of the list
		if (head != nullptr)
			head->prev = nullptr;//update the prev pointer and set it to null to avoid data leakage
		temp->next = nullptr;//update the next pointer and set it to null to avoid data leakage
		delete temp;//delete the node to avoid data leakage
		size--;

		return value;//return the value of the node deleted
	}

	//remove the last element in the list
	T removeLast() {
		if (isEmpty()) {
			cout << "Your List is Empty, You Can't Remove" << endl;
			return T();
		}//check if the list is empty

		T value = tail->data;//set the value of the node delete to return
		Node<T>* temp = tail;//a temp pointer to delete the node
		tail = tail->prev;
		if (tail != nullptr)
			tail->next = nullptr;//update the next pointer and set it to null to avoid data leakage
		temp->prev = nullptr;//update the prev pointer and set it to null to avoid data leakage
		delete temp;//delete the node to avoid data leakage
		size--;

		return value;//return the value of the node deleted

	}

	//remove a node at a given index 
	T removeAt(int index) {
		if (isEmpty()) {
			cout << "Your List is Empty, You Can't Remove" << endl;
			return T();
		}//check if the list is empty

		if (index < 0 || index >= size) {
			cout << "Your Index is Out of the Boundries" << endl;
			return T();
		}//ckeck if the index is out of boundry

		Node<T>* temp = head;
		for (int i = 0;i < index;i++) {
			temp = temp->next;
		}//trazverse through the list until the pointer points to the required node at the right index

		return(remove(temp));//call the remove function and remove the node

	}

	//remove the first occurance of an element
	bool remove(T e) {
		if (isEmpty()) {
			cout << "Your List is Empty, You Can't Remove" << endl;
			return false;
		}//check if the list is empty

		Node<T>* temp = head;//make a pointer to traverse through the list
		while (temp != nullptr) {
			if (temp->data == e){
				remove(temp);
				return true;
			}
			temp = temp->next;
		}//keep looping until the element is found and remove it 

		return false;//when element is not found return false to indicate that it is not
	}

	//returns the index of a given element, if not found it returns -1
	int indexOf(T e) {
		if (isEmpty()) {
			cout << "Your List is Empty" << endl;
			return -1;
		}//check if the list is empty

		int index =0;
		Node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->data == e) {
				return index;
			}
			temp = temp->next;
			index++;
		}
		return -1;

	}

	//check if the list contains a specific element
	bool contains(T e) {
		return indexOf(e) != -1;

	}

	//return a string visualisation of the queue 
	//same function implemented in all other data structures
	string toString() {
		string result = "[ ";
		Node<T>* trav = head;
		while (trav != nullptr) {
			result += to_string(trav->data);
			if (trav->next != nullptr)
				result += ", ";
			trav = trav->next;
		}
		result += " ]";
		return result;
	}


};

int main() {
	DoublyLinkedList<int> dll;

	cout << "Initial list: " << dll.toString() << endl;

	//add elements
	dll.add(10);
	dll.add(20);
	dll.addFirst(5);
	dll.addLast(30);
	cout << "After adding 5, 10, 20, 30: " << dll.toString() << endl;

	//peek first and last
	cout << "Peek first: " << dll.peekFirst() << endl;
	cout << "Peek last: " << dll.peekLast() << endl;

	//remove first and last
	cout << "Removed first: " << dll.removeFirst() << endl;
	cout << "Removed last: " << dll.removeLast() << endl;
	cout << "List after removing ends: " << dll.toString() << endl;

	//remove by index
	cout << "Removed at index 0: " << dll.removeAt(0) << endl;
	cout << "List after removing index 0: " << dll.toString() << endl;

	//add more and remove by value
	dll.add(40);
	dll.add(50);
	dll.add(60);
	cout << "After adding 40, 50, 60: " << dll.toString() << endl;

	bool removed = dll.remove(50);
	cout << "Tried removing 50: " << (removed ? "Success" : "Failed") << endl;
	cout << "List after removal: " << dll.toString() << endl;

	//contains and indexOf
	cout << "List contains 40? " << (dll.contains(40) ? "Yes" : "No") << endl;
	cout << "Index of 60: " << dll.indexOf(60) << endl;
	cout << "Index of 100: " << dll.indexOf(100) << endl;

	//clear the list
	dll.clear();
	cout << "After clearing: " << dll.toString() << endl;
	cout << "List is empty? " << (dll.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}

