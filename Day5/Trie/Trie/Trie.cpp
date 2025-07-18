#include <iostream>//for cin and cout

using namespace std;

//trie implementation

//node class
template<typename T>
class Node {
public:
    Node<T>* children[26];//array of pointers for all 26 letters from a to z to store for children
    bool isEndOfWord;//if a word ends here then it is true
    T value;//additional value can only be at the end of the word, it can be assiciated with the word

    //constructor, make all pointers point to nothing because there is no childer yet
    Node() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

//trie classs
template<typename T>
class Trie {
private:
    Node<T>* root;//pointer to the root node ( begining of the tree)

    //convert any char given to index to know what char we are working with now
    int charToIndex(char c) {
        return c - 'a';//where a is 0, so c will be known and stored in the right index
    }

public:

    //constructor
    Trie() {
        root = new Node<T>();
    }

    //insert a word with its value
    void insert(const string& word, const T& value) {
        Node<T>* node = root;//make a pointer to the root

        for (int i = 0; i < word.length(); ++i) {
            int index = charToIndex(word[i]);//loop through the word and find the char one by one, and their index

            if (node->children[index] == nullptr)
                node->children[index] = new Node<T>();//if char is not pointed at yet, point to it by the pointer

            node = node->children[index];//now go to the children and add the new letters to it until the last letter
        }

        node->isEndOfWord = true;//when the last letter is added make it end of the word
        node->value = value;//add the value to the end of the worf
    }

    //search for a word, and return a pointer to the related value to that word
    T* search(const string& word) {
        Node<T>* node = root;//start at root 

        for (int i = 0; i < word.length(); ++i) {
            int index = charToIndex(word[i]);

            if (node->children[index] == nullptr)
                return nullptr;//meanting the word is not found, because the expected letter is missing

            node = node->children[index];//else move down until we finish the whole word
        }

        if (node->isEndOfWord)
            return &(node->value);//return a pointer to the value when it is found
        else
            return nullptr;//return null if it is not found
    }

    //check if any word starts with this prefix
    bool startsWith(const string& prefix) {
        Node<T>* node = root;//start at root

        for (int i = 0; i < prefix.length(); ++i) {
            int index = charToIndex(prefix[i]);//get the letters of the prefix

            if (node->children[index] == nullptr)
                return false;//meanting the prefix is not found, because the expected letter is missing

            node = node->children[index];//else move down until we finish the whole word
        }

        return true;//found, since we went through the whole prefix
    }
};

int main() {
    Trie<int> trie;//create a Trie where values are integers

    //insert words and their values
    trie.insert("apple", 10);
    trie.insert("app", 5);
    trie.insert("bat", 7);
    trie.insert("ball", 8);
    trie.insert("cat", 8);
    trie.insert("call", 11);
    //tries using word with simillar prefixes to test the trie 

    //test full word search
    int* val;

    val = trie.search("apple");
    if (val)
        cout << "apple  " << *val << endl;
    else
        cout << "apple not found" << endl;

    val = trie.search("app");
    if (val)
        cout << "app  " << *val << endl;
    else
        cout << "app not found" << endl;

    val = trie.search("bat");
    if (val)
        cout << "bat  " << *val << endl;
    else
        cout << "bat not found" << endl;

    val = trie.search("bad");
    if (val)
        cout << "bad  " << *val << endl;
    else
        cout << "bad not found" << endl;

    //test prefix search
    cout << boolalpha; //print true/false instead of 1/0
    cout << "Starts with 'ba': " << trie.startsWith("ba") << endl;  
    cout << "Starts with 'ap': " << trie.startsWith("ap") << endl;  
    cout << "Starts with 'ca': " << trie.startsWith("ca") << endl;
    cout << "Starts with 'aj': " << trie.startsWith("aj") << endl;  

    return 0;
}