#include <iostream>//for cin and cout
#include <string>//for string funcitons 

using namespace std;

//stack implementation using dynamic arrays
template <typename T>
class ArrayStack {

private:
	T* array;//pointer to the array (stack)
	int capacity;//current possible capacity for the array
	int topIndex;//index of the top most element in the stack, will be -1 when empty, since 0 represents one element, this is the only logical thing to do

	//reize the array when it is full, the size is upon request 
	void resize(int newCapacity) {
		T* newArray = new T[newCapacity];//new array of the requested size
		for (int i = 0; i < size(); i++) {
			newArray[i] = this->array[i];
		}

		delete [] this->array;//dellocation of memory to avoid data leakage
		this->array = newArray;//point to the new array
		this->capacity = newCapacity;//update the capacity

	}
public:
	//defaul constructor for the stack
	ArrayStack() {
		capacity = 10;//can be anything, standard is 10
		array = new T[capacity];//set up the array (stack) with 10 empty slots
		topIndex = -1;//empty stack so the index of the first element will be =-1 as mentioned above

	}

	//destructor
	~ArrayStack() {
		delete[] this->array;
	}

	//add element at the top of the array (stack)
	void push(T e) {
		if (this->topIndex + 1 == this->capacity) {
			resize(this->capacity * 2); //double size if full
		}

		array[++this->topIndex] = e;//update the topIndex value and add the new value on top of the stack

	}

	//remove the element on top of the stack
	T pop() {
		if (isEmpty()){
			cout << "Stack is Empty Nothing to Pop" << endl;
			return T();//when stack is empty return a default value
		}
		
		return array[this->topIndex--];

	}

	//return the vlaue on top of stack without poping it
	T peek() {
		if (isEmpty()) {
			cout << "Stack is Empty Nothing to Peek" << endl;
			return T();//when stack is empty return a default value
		}

		return this->array[this->topIndex];

	}

	//check if the stack is empty
	bool isEmpty() {
		return this->topIndex == -1;//return true if the stack is empty, false if it is not

	}

	//return the current size of the stack
	int size() {
		return this->topIndex + 1;
	}
	
	//clear the stack 
	void clear() {
		this->topIndex = -1;// will ignore everything in the array and will override the other elements there when we want to add 

	}

	//string representation of the stack from bottom to top
	string toString() {
		if (isEmpty())
			return "[]";// when the stack is empty you return []

		string result = "[";//add an opening bracket at the begining
		for (int i = 0;i <= this->topIndex;i++) {
			result += to_string(this->array[i]);
			if (i != this->topIndex)
				result += ", ";//add a comma between each element
		}
		result += "]";//add a closing bracked at the end 
		return result;

	}

};

//stack implementation using linked lists
// 
//node class for the nodes in the linked list
template <typename T>
class Node {
public:
	T data;
	Node<T>* next;

	//constructor for the node with a given value
	Node(T value) {
		data = value;
		next = nullptr;
	}
};

//actual linked list class 
template <typename T>
class LinkedListStack {
private:
	Node<T>* top;//point to the top (last added element)
	int count;//to count the number of nodes in the list (stack)

public:

	//default constructor of the linked list stack
	LinkedListStack() {
		this->top = nullptr;//stack will be initially empty so top pointer will point to nothing
		this->count = 0;//since stack is empty the number of nodes insdie the stack is 0
	}

	//destructor
	~LinkedListStack() {
		clear();
	}

	//push a new element to the top of the stack 
	void push(T e) {
		Node<T>* node = new Node<T>(e);//create the node with the value required
		node->next = this->top;//add the new node to the list by making it point to the current top node
		this->top = node;//update the top node pointer, and make it point to the new node
		this->count++;//update the counter and add 1 top reflect that a new node was added
	}

	//pop the top most (latest added) node from the stack (list)
	T pop() {
		if (isEmpty()) {
			cout << "Stack is Empty Nothing to Pop" << endl;
			return T();
		}
		Node<T>* temp = this->top;
		T value = temp->data;
		this->top = this->top->next;
		delete temp;
		this->count--;
		return value;

	}

	//peek at the top most element in the stack 
	T peek() {
		if (isEmpty()) {
			cout << "Stack is Empty Nothing to Peek at" << endl;
			return T();
		}
		
		return this->top->data;
	}

	//check if the stack (list) is empty
	bool isEmpty() {
		return this->top == nullptr;
	}

	//return the current size of the stack
	int size() {
		return this->count;
	}

	//clear the entire stack (list)
	void clear() {
		Node<T>* temp = this->top;//add a temp pointer to the node to delete
		while (temp != nullptr) {
			this->top = this->top->next;
			delete temp;
			temp = this->top;
		}//keep looping until everything is deleted
		this->top = nullptr;//extra step to avoid data leakage
		this->count = 0;//reset the counter
	}

	//string representation of the stack from bottom to top
	string toString() {
		if (isEmpty()) return "[]";//return [] when the stack is empty

		string result = "[";//make [ the start of the string
		T* reversed = new T[count];//the stack should be reversed, so it is stored reversly in an array so that we get the elements from bottom to top
		Node<T>* current = this->top;//start from the top of the stack
		int i = count - 1;
		while (current != nullptr) {
			reversed[i--] = current->data;
			current = current->next;
		}//fill the array from the left to the right

		for (int j = 0; j < count; j++) {
			result += to_string(reversed[j]);
			if (j != count - 1)
				result += ", ";
		}//store the values from the array to the result string

		result += "]";//close the string 
		delete[] reversed;//delete the dynamic array to avoid memory leakage
		return result;//return the string
	}

};
int main() {
	//declare both stacks
	ArrayStack<int> arrayStack;
	LinkedListStack<int> linkedStack;

	//push elements to both
	arrayStack.push(10);
	linkedStack.push(10);
	arrayStack.push(20);
	linkedStack.push(20);
	arrayStack.push(30);
	linkedStack.push(30);

	//show stacks
	cout << "ArrayStack: " << arrayStack.toString() << endl;
	cout << "LinkedListStack: " << linkedStack.toString() << endl;
	cout << "---------------------------------------------" << endl;

	//peek at top
	cout << "Top of ArrayStack: " << arrayStack.peek() << endl;
	cout << "Top of LinkedListStack: " << linkedStack.peek() << endl;
	cout << "---------------------------------------------" << endl;

	//pop from both
	cout << "Popped from ArrayStack: " << arrayStack.pop() << endl;
	cout << "Popped from LinkedListStack: " << linkedStack.pop() << endl;
	cout << "---------------------------------------------" << endl;

	//show stacks after pop
	cout << "ArrayStack after pop: " << arrayStack.toString() << endl;
	cout << "LinkedListStack after pop: " << linkedStack.toString() << endl;
	cout << "---------------------------------------------" << endl;

	//check size
	cout << "ArrayStack size: " << arrayStack.size() << endl;
	cout << "LinkedListStack size: " << linkedStack.size() << endl;
	cout << "---------------------------------------------" << endl;

	//check isEmpty
	cout << "ArrayStack is empty? " << (arrayStack.isEmpty() ? "Yes" : "No") << endl;
	cout << "LinkedListStack is empty? " << (linkedStack.isEmpty() ? "Yes" : "No") << endl;
	cout << "---------------------------------------------" << endl;

	//clear both
	arrayStack.clear();
	linkedStack.clear();

	//show stacks after clear
	cout << "ArrayStack after clear: " << arrayStack.toString() << endl;
	cout << "LinkedListStack after clear: " << linkedStack.toString() << endl;
	cout << "---------------------------------------------" << endl;

	//final empty check
	cout << "ArrayStack is empty? " << (arrayStack.isEmpty() ? "Yes" : "No") << endl;
	cout << "LinkedListStack is empty? " << (linkedStack.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}
