#include <iostream>//for cin and cout
#include <list>//use list to implement the chaining hash table
using namespace  std;

//hash table implementation, 2 seperate classes, one for openaddressing collision handeling and the other is for chaining collision handeling

const int upperLimit = 100;

//hasing table using chaining, each index will have a list where it has multiple keys
class HashTableChaining {
private:
	list<pair<string, int>> table[upperLimit];//used pair to allow 2 values be considered as one in the table, and list to make a list of elements that have the same index
	int tableSize;//actual table size entered by the user

	//hash function that takes the key and give the index of it 
	int hashFunc(string key) {
		int sum = 0;
		for (int i = 0;i < key.length();i++) {
			sum += (int)key[i];//make the string ins ASCII value
		}
		return sum % tableSize;//return the index of the string, make sure it is in the table boundries

	}

public:

	//constructor
	HashTableChaining(int size) {
		tableSize = size;
	}

	//insert a value into the hash table
	void insert(string key,int value) {
		int index = hashFunc(key);//will get the index of the string and allow us to store it with the value we want to store
		table[index].push_back(make_pair(key, value));//add the string and the value as a pair in the right place in the hash table
	}

	//search for a given key and check if it is avaliable
	bool get(string key, const int& value) {
		int index = hashFunc(key);//get the expected index of that key
		//go through the list of the given index in the hash table and find it
		for (auto i = table[index].begin();i != table[index].end();i++) {

			if (i->first == key)//meaning the first pair was the actual key
			{
				return true;//it was found
			}

		}//go to the list of the index, search through 
		return false;//we looped through the whole list and the key was not found so return false
	}

	//remove a given key
	bool remove(string key) {
		int index = hashFunc(key);//find the index of the list of the key 

		for (auto i = table[index].begin();i != table[index].end();i++)//go through the list that must have the key
		{
			if (i->first == key)//if the string was found then delete it and it will automatically hande it by the list class
			{
				table[index].erase(i);//delete key
				return true;//return true meaning it was deleted
			}
		}
		return false;//we went through the whole list and the key was not found so nothing to delte
	}

};

//hasing table using open addressing, if a slot is taken find the next empty slot
class HashTableOpenAddressing {
private:
	string keys[upperLimit];//an array to store the keys with max size 100
	int values[upperLimit];//an array to store the values of each key
	bool used[upperLimit];//and array to store wether this index is taken or not
	int tableSize;//actual table size entered by the user

	//hash function that takes the key and give the index of it 
	int hashFunc(string key) {
		int sum = 0;

		for (int i = 0;i < key.length();i++) {
			sum += key[i];//make the string ins ASCII value
		}

		return sum % tableSize;//index should not go out of the table boundries so we do mode tableSize, this will also allow the index to return to 0 when we reach max index in the table
	}

public:

	//constructor
	HashTableOpenAddressing(int size) {
		tableSize = size;
		for (int i = 0; i < tableSize; i++) {
			keys[i] = "";//fill the keys as empty initially
			values[i] = -1;//-1 will be the value that represent an empty key (common practice)
			used[i] = false;//flase indicates that this place is not taken
		}//loop through the 3 arrays we made
	}

	//insert a value into the hash table
	void insert(string key, int value) {
		int index = hashFunc(key);//find the initial index of the key
		int start = index;//an int the refer to the first value of the index, will be used to only go through the table once and find if it is full

		while (used[index] && keys[index] != key) {
			index = (index + 1) % tableSize;//update the index, increase by one, but keep it in the boundries of the table
			if (index == start)
				return;//meaning a full loop was made around the table and the table is full

		}//loop through the used and keys tables until you find an empty slot
		
		//if an empty slot was found update the tables
		keys[index] = key;//set the key table
		values[index] = value;//set the value and make it refer to the string
		used[index] = true;//upddate it to true so we know that it was taken
	}

	//search for a given key and check if it is avaliable
	bool get(string key, const int& value) {

		int index = hashFunc(key);//find the expected index of the key
		int start = index;//an int the refer to the first value of the index, will be used to only go through the table once and find if it is full

		while (used[index]) {
			if (keys[index] == key)
				return true;//ke was found
			index = (index + 1) % tableSize;//update the index go to the next expected place where the key is expected to be
			if (start == index)
				break;//the key is not found so break out of the loop

		}//loop through the used array until you find the key, or not
		return false;//return false because it was not found
	}

	//remove a given key
	bool remove(string key) {
		int index = hashFunc(key);//find the expected index of the key
		int start = index;//an int the refer to the first value of the index, will be used to only go through the table once and find if it is full
		while (used[index]) {
			if (keys[index] == key){
				keys[index] = "";//update the keys and set the slot to empty
				values[index] = -1;//update the values and set the slot to empty
				used[index] = false;//update the used and set the slot to empty
				return true;
			}//if it was found

			index = (index + 1) % tableSize;//if it was not found update the index
			if (index == start)
				break;//the key is not found so break out of the loop
		}
		return false;//return false because it was not found
	}
};

int main() {
	//allow user choose the size of table
	int size;
	cout << "Enter hash table size (max " << upperLimit << "): ";
	cin >> size;

	//error handling
	if (size <= 0 || size > upperLimit) {
		cout << "Invalid size.\n";
		return 1;
	}

	//test adding and getting and removing in the hash table using chaining
	cout << "\nTesting Hash Table with Chaining\n";
	HashTableChaining chaining(size);
	chaining.insert("Jaber", 99);
	chaining.insert("Ibrahim", 99.6);
	chaining.insert("Zaina", 100);

	if (chaining.get("Jaber", size)) cout << "Found Jaber in chaining\n";
	chaining.remove("Jaber");
	if (!chaining.get("Jaber", size)) cout << "Jaber removed from chaining\n";

	//test adding and getting and removing in the hash table using open addressing
	cout << "\nTesting Hash Table with Open Addressing \n";
	HashTableOpenAddressing open(size);
	open.insert("Jaber", 99);
	open.insert("Ibrahim", 99.6);
	open.insert("Zaina", 100);

	if (open.get("Ibrahim", size)) cout << "Found Ibrahim in open addressing\n";
	open.remove("Ibrahim");
	if (!open.get("Ibrahim", size)) cout << "Ibrahim removed from open addressing\n";

	return 0;
}