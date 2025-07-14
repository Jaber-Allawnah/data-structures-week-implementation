#include <iostream>
#include <string>

using namespace std;

//dynamic array class
template <typename T>
class dynamicArray {

private:
	T* array;//pointer to my array of type T
	int length;//will have the current length of my array
	int size;//will have the total size of my arry

	void resize(int newSize) {
		T* arrayNew = new T[newSize];//make a new array of new size
		for (int i = 0;i < newSize;i++) {
			arrayNew[i] = this->array[i];//copy old items of array
		}
		delete[] array;//remove old array to avoid memory leakage
		array = arrayNew;//make pointer to new array
		this->size = newSize;//update array size
	}

public:

	//defaul constructor 
	dynamicArray() {
		this->length = 0;
		this->size = 16;
		this->array = new T[size];
	}

	//constructor with custom size 
	dynamicArray(int size) {
		this->length = 0;
		this->size = size;
		this->array = new T[size];
	}

	//destructor
	~dynamicArray() {
		delete[] this->array;
	}

	//return current size of array
	int currentSize() {
		return this->length;
	} 

	//return true if array is empty and false if not
	bool isEmpty() {
		return (this->length == 0);
	} 

	// get a requested element using index, with error handling if index was out of bounds
	T get(int index) {
		if (index<0 || index>size - 1) {
			cout << "Error, your index is out of boundries";
			return T();// return default value
		}//error handling when the required index is out of boundries

		return array[index];
	}

	//set a given element at a given index, with error handling if index was out of bounds
	T set(int index, T e) {
		if (index<0 || index>size - 1) {
			cout << "Error, your index is out of boundries";
			return T();// return default value
		}//error handling when the required index is out of boundries

		this->array[index] = e;
	}

	//resets the array to original 
	void clear() {
		for (int i = 0;i < size;i++) {
			this->array[i] = T();
		}
		this->length = 0;
	}

	//add element at the end 
	void add(T e) {
		if (length >= size) {
			cout << "Your array is full and it will be resized";

			resize(this->size==0?1:this->size*2);//duplicate the array size , or set it to one if the size is 0 
		}

		this->array[this->length] = e;//add the element
		this->length++;//update the length of the array, add one 
	}

	//remove element at a given index and return it 
	T removeAt(int index) {
		if (index<0 || index>size - 1) {
			cout << "Error, your index is out of boundries";
			return T();// return default value
		}//error handling when the required index is out of boundries

		T removed = this->array[index];
		for (int i = index; i < this->length - 1;i++) {
			this->array[i] = this->array[i + 1];
		}
		this->length--;//update the length of the array, renmove one 

		return removed;
	}

	//remove the first occurance of an element ( return true if successful, and false if element was not found)
	bool remove(T e) {
		int i = indexOf(e);
		if (i == -1)
			return false;
		removeAt(i);
		return true;
	}

	//return indix of the first occurance of a given element
	int indexOf(T e) {
		for (int i = 0;i < this->length;i++) {
			if (this->array[i] == e)
				return i;
		}
		return -1;//-1 if element not found

	}

	//return true if element exists in the array and false if not
	bool contains(T e) {
		return indexOf(e) != -1;
	}

	//convert the contents of the array to a string to be easilty displayed
	string toString() {
		if (length == 0)
			return "[]";//if array is empty return []

		string result = "[";// set ] as the begining of the array
		for (int i = 0; i < length; i++) {
			result += to_string(array[i]);//to_string converts any value to string, and += by default will do concatination
			if (i != length - 1)
				result += ", ";// for organization purposes, if this is not the last element add , after it 
		}
		result += "]";//set ] as the end of the array
		return result;
	}

	//return a pointer to the first element of the array
	T* begin() {
		return array;
	}

	//return a pointer to the last element of the array
	T* end() {
		return array + length;
	}
};

int main() {
	dynamicArray<int> arr;//create a dynamic array of integers

	arr.add(10);
	arr.add(20);
	arr.add(30);

	cout << "Initial array: " << arr.toString() << endl;

	arr.removeAt(1);//remove value at index 1 (20)
	cout << "After removing index 1: " << arr.toString() << endl;

	arr.set(1, 99); //set value at index 1 to 99
	cout << "After setting index 1 to 99: " << arr.toString() << endl;

	//range-based loop using begin() and end(), they will be called automatically when provided in class, the compiler will map through the array
	cout << "Iterating with range-based loop: ";
	for (int value : arr) {
		cout << value << " ";
	}
	cout << endl;

	//contains and indexOf
	cout << "Contains 99? " << (arr.contains(99) ? "Yes" : "No") << endl;
	cout << "Index of 99: " << arr.indexOf(99) << endl;
	cout << "Size of array: " << arr.currentSize() << endl;

	//clear the array
	arr.clear();
	cout << "After clearing: " << arr.toString() << ", isEmpty? " << (arr.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}