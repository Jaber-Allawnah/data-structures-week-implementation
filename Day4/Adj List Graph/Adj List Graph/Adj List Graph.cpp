#include <iostream>//for cin and cout
#include <list>//to use it in implementing the ajacnecy list

using namespace std;

//basic graph (adjacency list representation)

const int maxNodes = 100;

//graph class
template <typename T>
class Graph {
private:
	list<T> adj[maxNodes];//make a list that can handle up tp 100 nodes
	int nodeCount;//current number of nodes the graph can hold
	int count;

public:

	//constructor
	Graph(int nodeCount) {
		this -> nodeCount = nodeCount;//set the number of nodes in the graph as requestedd
		count = 0;
	}

	//add an edge between 2 given nodes in the graph
	void addEdge(int index, T v) {
		adj[index].push_back(v);//add the node with value v to the addjacency list of node index
		count++;
	}

	//remove edge
	void removeEdge(int index, T v) {
		adj[index].remove(v);//remove edge with value v, from the adj list of node at index 
		count--;
	}

	//print graph 
	void printGraph() {
		for (int i = 0;i < nodeCount;i++) {
			cout << "The node at position " << i << ": ";
			for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
				cout << *j << " ";
			}//loop throgh the graph and pribt the neighbors for each node
			cout << endl;
		}
	}

	//clear the graph
	void clear() {
		for (int i = 0;i < nodeCount;i++) {
			adj[i].clear();//clear the adj list for each node
			count = 0;
		}
	}//evntually the graph will be empty

	//check if the graph is empty
	bool isEmpty() {
		return count == 0;

	}
};

int main() {
	//create a graph with 5 nodes (index 0 to 4)
	Graph<int> g(5);

	//add edges
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	cout << "Graph after adding edges:\n";
	g.printGraph();

	//remove an edge
	g.removeEdge(1, 4);
	cout << "\nGraph after removing edge from node 1 to 4:\n";
	g.printGraph();

	//check if graph is empty
	cout << "\nIs the graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;

	//clear the graph
	g.clear();
	cout << "\nGraph after clearing:\n";
	g.printGraph();

	//check again if graph is empty
	cout << "\nIs the graph empty now? " << (g.isEmpty() ? "Yes" : "No") << endl;

	return 0;
}
