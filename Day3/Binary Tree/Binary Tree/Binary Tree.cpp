#include <iostream>//for cin and cout
#include <string>//for string functions

using namespace std;
//binary tree implementation with tree traversal algorithms (inorder, preorder, postorder)

//binary tree node class
template <typename T>
class Node {
public:
	Node<T>* left;//pointer to the left subtree
	Node<T>* right;//pointer to the right subtree
	Node<T>* parent;//pointer to the parent
	T data;//data of the node

	//constructor
	Node(int value,	Node<T>* parent = nullptr) {
		this->data = value;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = parent;
	}
};

//binary tree class
template <typename T>
class BinaryTree {
private:
	Node<T>* root;//pointer to the root of the node

	//clear the subtree of a given node, called in private to prevent using it from outside
	void clear(Node<T>* node) {
		if (node == nullptr)
			return;//if node does not have a subtree

		clear(node->left);//recursivly delete the left subtree until the root is reached
		clear(node->right);//recursivly delete the right subtree until the root is reached

		delete node;//delete the current node to avoid memory leakage
	}

	//return the number of nodes in a subtree of a given node
	int size(Node<T>* node) {
		if (node == nullptr)
			return 0;//if the node does not exist return 0

		return 1 + size(node->right) + size(node->left);//recursivly count the number of children for each node and add 1 to them the 1 refers to the parent

	}

	//return the current height of subtree of a given node
	int height(Node<T>* node) {
		if (node == nullptr)
			return -1;//best practice is to return -1 when there is no tree to refer to the tree's height

		return 1 + max(height(node->right), height(node->left));//recursivly find the max height between the left/right subtrees and add 1 to them
		//when a tree has one node the equation will be :1 + max(-1, -1) = 0 correct height for a leaf

	}

	//preorder a subtree of a given node (root,left,right)
	void preorder(Node<T>* node) {
		if (node == nullptr)
			return;//if the node does not exist return and do nothing

		cout<< node->data << " ";
		preorder(node->left);
		preorder(node->right);
		//recursivly type the preorder of the tree

	}

	//preorder a subtree of a given node (left,root,right)
	void inorder(Node<T>* node) {
		if (node == nullptr)
			return;//if the node does not exist return and do nothing
		
		preorder(node->left);
		cout << node->data << " ";
		preorder(node->right);
	}

	//postordera subtree of a given node (left,right,root)
	void postorder(Node<T>* node){
		if (node == nullptr)
			return;//if the node does not exist return and do nothing

		preorder(node->left);
		preorder(node->right);
		cout << node->data << " ";

	}

	//count the number of leaves for a subtree of a given node  
	int countLeaves(Node<T>* node) {
		if (node == nullptr)
			return 0;//if the node does not exist return 0
		if (!node->left && !node->right) 
			return 1;//if there are no childrn for the node

		return countLeaves(node->right) + countLeaves(node->left);//recursibly keep going down the tree until you reach leaves and count them 
	}

public:

	//construcor
	BinaryTree() {
		root = nullptr;//start with a tree with one node only
	}

	//destructor
	~BinaryTree() {
		clear();//this will call the clear fucntion
	}


	//clear tree
	void clear() {
		clear(root);//clear from the root, recrsibly go down to the bottom
		root = nullptr;//make the root = nullptr to avoid any leakage
	}

	//check if the tree is empty
	bool isEmpty() {
		return root == nullptr;
	}

	//return the current size of the tree
	int size() {
		return size(root);
	}

	//count the number of leaves in the tree
	int countLeaves() {
		return countLeaves(root);
	}

	//finbd the height of the tree
	int height() {
		return height(root);
	}

	//set root node value
	void insert(int value) {
		if (root == nullptr)
			root = new Node<T>(value);
	}

	//get the pointer of the root node of the tree
	Node<T> * getRoot() {
		return root;
	}

	//preorder the tree from the root
	void preorder() {
		preorder(root);
		cout << endl;
	}

	//inorder the tree from the root
	void inorder() {
		inorder(root);
		cout << endl;
	}

	//postorder the tree from the root
	void postorder() {
		postorder(root);
		cout << endl;
	}

};

int main() {
	BinaryTree<int> tree;

	//insert root to the tree because it is empty
	tree.insert(1);

	//manually add children to the tree, in BST there is adding logic and order so it will be implemented automatically
	Node<int>* root = tree.getRoot();//get the root of the ree
	root->left = new Node<int>(2, root);
	root->right = new Node<int>(3, root);
	root->left->left = new Node<int>(4, root->left);
	root->left->right = new Node<int>(5, root->left);

	//traversals algorithms as required in the task
	cout << "Preorder: "; tree.preorder();
	cout << "Inorder: "; tree.inorder();
	cout << "Postorder: "; tree.postorder();

	//tree information
	cout << "Size: " << tree.size() << endl;
	cout << "Height: " << tree.height() << endl;
	cout << "Leaf Count: " << tree.countLeaves() << endl;
	cout << "Is Empty? " << (tree.isEmpty() ? "Yes" : "No") << endl;

	//clear tree and check again if it worked
	tree.clear();
	cout << "After clearing, is empty? " << (tree.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}