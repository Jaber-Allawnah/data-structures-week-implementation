#include <iostream>//fir cin and cout

using namespace std;

//unios find using disjoint set implmentation

//disjoint set class
template<typename T>
class DisjointSet {
private:
    T* parent;//the parent element, in disjoint set , there is one element that represent all the other elements
    int* rank;//height of the tree
    int size;//the current number of elements in the set

public:

    //constructor
    DisjointSet(int n) {
        size = n;
        parent = new T[n];
        rank = new int[n];

        for (int i = 0; i < n; ++i) {
            parent[i] = i;//each element at the begining will be it's own parent
            rank[i] = 0;//initial rank for all
        }
    }

    //find the representative of the set that has x in it
    T find(T x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);//path compression
        return parent[x];
    }

    //union 2 disjoint sets that have x and y in them
    void unionSets(T x, T y) {
        T rootX = find(x);//find the set of x
        T rootY = find(y);//find the set of y

        if (rootX == rootY)
            return;//if they are in the same set, then finish

        //make the set with smaller rank attached under the tree with the bigger rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;//make x the parent 
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;//make y the parent
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;//we can use rootX or rootY, add one to the rank since they are of the same height
        }
    }

    //destructor
    ~DisjointSet() {
        delete [] parent;//delete to avoid memory leakage
        delete [] rank;//delete to avoid memory leakage
    }
};

int main() {
    //create a Disjoint Set with 7 elements
    DisjointSet<int> disjointSet(7);

    //union some pairs into different sets
    disjointSet.unionSets(0, 1);
    disjointSet.unionSets(1, 2);
    disjointSet.unionSets(3, 4);
    disjointSet.unionSets(5, 6);
    disjointSet.unionSets(4, 5);

    //test connectivity between elements to test find function
    cout << boolalpha;
    cout << "Are 0 and 2 connected? " << (disjointSet.find(0) == disjointSet.find(2)) << endl; 
    cout << "Are 0 and 4 connected? " << (disjointSet.find(0) == disjointSet.find(4)) << endl;
    cout << "Are 3 and 6 connected? " << (disjointSet.find(3) == disjointSet.find(6)) << endl; 

    return 0;
}