#include <iostream>//for cin and cout
#include <queue>//already implemented in day 2 so used to reduve code complexity
#include <stack>//aleady implmeneted in day so used to reduve code complexity

using namespace std;

//binary search tree code with tree traversal algorithms (inorder, preorder, postorder), used the code in the Youtube video for reference

//tree node class
template <typename T>
class Node {
public:
	T data;//data inside the node
	Node<T>* left;//pointer to the left subtree
	Node<T>* right;//pointer to the right subtree
	Node<T>* parent;//pointer to the parent of the node

    //constructor
    Node(T value, Node* parent = nullptr) //added default value for the parent node
    {
        data = value;
        left = right= nullptr;
        this->parent = parent;
    }
};

//binary search tree class
template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;//pointer to the root node of the tree
    int nodeCount;//counter for the current number of nodes in the tree 

    //add a value to the tree and return a pointer to the node
    Node<T>* add(Node<T>*node,T value, Node<T>* parent) {
        if (node == nullptr)
            return new Node<T>(value, parent);//if the node does not exist, meaning there is no tree just make it and return it
        
        //if there is a tree, then you shouldd find the right place to add the new node to
        //check if the value is < or > from the node
        if (value < node->data)//value is smaller than the parent so we should go and add it to the left
            node->left=add(node->left, value, node);
        else
            node->right = add(node->right, value, node);//value is greated than the parent so we should go and add it to the right
        return node;
    }

    //remove a node from the tree
    Node<T>* remove(Node<T>* node, T value) {
        if (node == nullptr) return nullptr;//meaning there is no tree and you can't remove anything

        //step one is find the value
        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        //delete the node 
        //case 1
        else{
        if (node->left == nullptr) {
            Node<T>* temp = node->right;//first right successor
            if (temp) temp->parent = node->parent;//update the parent of the successor and make in the right place
            delete node;//remvoe the node from the tree, there will be no data leakage
            return temp;//return the new root of the subtree
        
    }//check if the node has no left subtree, make the right successor the root of that subtree and delete the old node
        else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            if (temp) 
                temp->parent = node->parent;//update the parent of the successor and make in the right place
            delete node;//remvoe the node from the tree, there will be no data leakage
            return temp;//return the new root of the subtree
            
        }//check if the node has no right subtree, make the left successor the root of that subtree and delete the old node 

        //last case is that there is 2 subtree so we either replace the root with the min node of the right subtree and delete it
        //or we can find the max node of the left subtree and make it the root and delete it 

        Node<T>* temp = findMin(node->right);//findMin will go through the whole subtree and find the smallest value in the tree
        node->data = temp->data;//update the data
        node->right = remove(node->right, temp->data);//delete the minimum rightmost node recursivly
    }
        return node;
    }

    //check if the tree contains a node with a given value
    bool contains(Node<T>* node, T value) {
        if (node == nullptr) return false;//there is no tree so it does not contain anything, or we reached the leaf
        //check if the value is supposed to be on the right or the left of the tree
        if (value < node->data) return contains(node->left, value);
        else if (value > node->data)return contains(node->right, value);

        else return true;//meaning value=the current node so it is found

    }

     //find the minimum node in a tree
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr)//still have not reached the leaf of the nodes
        {
            node = node->left;//move to the left until you exit of the while loop
        }

        return node;
    }

    //find the height of the tree
    int height(Node<T>*node) {
        if (node == nullptr) return 0;//meaning there is not tree
        return 1 + max(height(node->left), height(node->right));//add 1 (node) to the longest height subtree

    }

    //preorder traversal (parent,left,right)
    void preorder(Node<T>* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    //inorder traversal (left,parent,right)
    void inorder(Node<T>* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    //postorder traversal (left,right,parent)
    void postorder(Node<T>* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    //clear the tree recursivly
    void clear(Node<T>*node) {
        if (node == nullptr) return;//there is not tree and nothing to clear
        clear(node->left);//clear the left subtree
        clear(node->right);//clear the right subtree
        delete node;//delete the final node in the tree

    }

public:


    //constructor
    BinarySearchTree() {
        root = nullptr;
        nodeCount = 0;
    }

    //destructor 
    ~BinarySearchTree() {
        clear(root);
    }

    //add node to the tree
    bool add(T value) {
        if (contains(value)) return false;//prevent any duplicates 
        root = add(root, value, nullptr);//add the node recursivly 
        nodeCount++;//update the count of nodes
        return true;//node added 
    }

    //remove node from the tree
    bool remove(T value) {
        if (!contains(value)) return false;//if the node is not there then you can't remove
        root = remove(root, value);//remove the node from the right place using the right case
        nodeCount--;//update the count of nodes
        return true;//node removed
    }

    //check if the tree contains a node
    bool contains(T value) {
        return contains(root, value);
    }

    //check the number of nodes in the tree
    int size() {
        return nodeCount;
    }

    //get tree height
    int height() {
        return height(root);
    }

    //traversal algorithms on the tree 
    
    //traverse in preorder
    void preorder() {
        preorder(root);
        cout << endl;
    }

    //traverse in inorder
    void inorder() {
        inorder(root);
        cout << endl;
    }

    //traverse in postorder
    void postorder() {
        postorder(root);
        cout << endl;
    }

   
};

int main() {
    BinarySearchTree<int> bst;

    //add values to the tree
    bst.add(50);
    bst.add(30);
    bst.add(70);
    bst.add(20);
    bst.add(40);
    bst.add(60);
    bst.add(80);


    //traversal algorithms check
    cout << "Inorder traversal (should be sorted): ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Tree contains 40? " << (bst.contains(40) ? "Yes" : "No") << endl;
    cout << "Tree contains 99? " << (bst.contains(99) ? "Yes" : "No") << endl;

    cout << "Size of tree: " << bst.size() << endl;
    cout << "Height of tree: " << bst.height() << endl;

    //remove a node with two children
    bst.remove(50);
    cout << "Inorder after removing 50: ";
    bst.inorder();

    //remove leaf node
    bst.remove(20);
    cout << "Inorder after removing 20: ";
    bst.inorder();

    //remove node with one child
    bst.remove(30);
    cout << "Inorder after removing 30: ";
    bst.inorder();

    cout << "Final size of tree: " << bst.size() << endl;
    cout << "Final height of tree: " << bst.height() << endl;

    return 0;
}
