#include <iostream>
#include <string>
using namespace std;

//a class for each node in the list
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

//the linked list class
template <typename T>
class SinglyLinkedList {
private:

	Node<T>* head;//refrence to the first element in the list
	int length;//show the number of elements in the list

public:

	//default constructor
	SinglyLinkedList() {
		this->head = nullptr;
		this->length = 0;
	}

	//destructor, remove all nodes from the list
	~SinglyLinkedList() {
		clear();
	}

	//return the size of the list
	int size() {
		return this->length;
	}

	//check if list is empty or not
	bool isEmpty() {
		return this->length == 0;
	} 
	
	//add to the end of the list
	void add(T e) {
		Node<T>*node = new Node<T>(e);//create the node to add with the given value,
		if (this->head == nullptr) {
			this->head = node;
		}//check if the list is empty and add the node as the first node in the list by poiting the header pointer to it 
		else {
			Node<T>* temp = this->head;//make a temp pointing that will traverse until it reaches the last node
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = node;//add the node to the end of the list
		}

		this->length++;//increase the length by one since we have a new node in the list

	}

	//get value by given index
	T get(int index) {
		if (index < 0 || index >= this->length) {
			cout << "Index out of bounds.\n";
			return T();
		}//error handling check if index is out of boundries

		Node<T>* temp = this->head;//start at header 

		for (int i = 0;i < index;i++) {
			temp = temp->next;
		}//keep going unti you reach the required index

		return temp->data;//return the data in the node in the right index

	}

	//set the value of a node in a given index
	void set(int index, T e) {
		if (index < 0 || index >= this->length) {
			cout << "Index out of bounds.\n";
			return;
		}//error handling if index is out of boundries

		Node<T>* temp = this->head;//start at head
		for (int i = 0;i < index;i++) {
			temp = temp->next;
		}//keep going until you reach the required node 

		temp->data = e;//update the value of the node
		return;
		

	}

	//remove node at a given index
	T removeAt(int index) {
		if (index < 0 || index >= length) {
			cout << "Index out of bounds.\n";
			return T();
		}//error handling if index is out of boundries

		Node<T>* temp;
		T removedValue;

		if (index == 0) {
			temp = this->head;
			head = this->head->next;
		}//case 1 (remove the header)
		else {
			Node<T>* prev = head;//staring at header
			for (int i = 0; i < index - 1; i++)
				prev = prev->next;//keep going until you reach the required node

			temp = prev->next;
			prev->next = temp->next;
			//update the pointers 
		}//case 2 remove an internal node, 

		removedValue = temp->data;//get the value of the node removed
		delete temp;//delete to avoid memory leakage
		length--;//reduce the length by 1 since one node is removed
		return removedValue;//return the value of the removed node 
	}

	//remove the first occurance of a value
	bool remove(T e) {
		int index = indexOf(e);//get the index of the first occurance of a value
		if(index ==-1)
		{
			return false;
		}

		removeAt(index);//function call to remove the value from the given index
		return true;
	}

	//return the index of the first occurance of a value
	int indexOf(T e) {
		int index = 0;
		Node<T>* temp = this->head;//start from header

		for (int i = 0;temp!=nullptr;i++) {
			if (temp->data == e)
				return i;
			temp = temp->next;
		}//keep going until you reach the value and return it's index

		return -1;//if value not found then return -1

	}

	//check if the list contains a specific element or not 
	bool contains(T e) {
		return indexOf(e) != -1;
	}

	//clear the list and remove all the nodes
	void clear() {
		if (this->length == 0)
			return;//already clear
		Node<T>* temp1 = this->head;//start from header

		while (temp1 != nullptr) {
		Node<T>* temp2 = temp1->next;//2 pointers traversing to achive the clearance of the list
		temp1->next = nullptr;
		delete temp1;//to avoid memory leakage
		temp1 = temp2;
		}//keep going until temp1 points to nothing, indicating the evey node is now removed

		length = 0;//upadte the length and set it to 0


	}

	//return the contents of the list as one string to see the content
	string toString() {
		if (length == 0)
			return "[]";//when the list is empty return []
		
		string result = "[";//set [ as the begining of the string
		Node<T>* temp = this->head;//strart from head
		while (temp != nullptr) {
			result += to_string(temp->data);

			if (temp->next != nullptr)
				result += ", ";// for organization, if this is not the last element add a , after it 
			
			temp = temp->next;
		}//keep going until all elements are added to the string

		result += "]";//set ] as the end of the string
		
		return result;//return the string 
	}

};

int main() {
	SinglyLinkedList<int> list;

	list.add(10);
	list.add(20);
	list.add(30);

	cout << "Initial list: " << list.toString() << endl;

	list.set(1, 99);
	cout << "After setting index 1 to 99: " << list.toString() << endl;

	list.removeAt(0);
	cout << "After removing index 0: " << list.toString() << endl;

	cout << "Contains 99? " << (list.contains(99) ? "Yes" : "No") << endl;
	cout << "Index of 99: " << list.indexOf(99) << endl;
	cout << "Size of list: " << list.size() << endl;

	list.clear();
	cout << "After clearing: " << list.toString() << ", isEmpty? " << (list.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}
