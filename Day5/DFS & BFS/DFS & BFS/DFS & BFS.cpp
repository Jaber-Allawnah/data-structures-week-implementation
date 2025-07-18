#include <iostream>//for cin and cout
#include <queue>//for BFS nodes storage, already implemented so used it to ease out the process
#include <stack>// for DFS using nodes storage, already implemented so used it to ease out the process

using namespace std;

//graph traversal (BFS/DFS)

const int MAX = 100; //maximum number of nodes supported in the graph

//graph class with adjacency matrix, BFS, and DFS
class Graph {
private:
    int adjMatrix[MAX][MAX];//adjacency matrix to represent edges in the graph
    int numVertices;//current number of vertices in the graph

public:

    //constructor
    Graph(int num) {
        numVertices = num;//make the number of nodes in the graph as required

        //initialize adjacency matrix with zeros (no edges)
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                adjMatrix[i][j] = 0;//loop through the whole matrix and make it zeros
    }

    //add an edge between two given nodes, the graph will be undirected by default unless it is said that it is not
    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;//1 means there is an edge between u and v
        if (!directed)
            adjMatrix[v][u] = 1;//else it will be 0, becuase the edge is in one direction
    }

    //Breadth-First Search from a given node
    void bfs(int start) {
        bool visited[MAX] = { false };//track if a node is visited so we do not loop in all directions, initially non of them is visited
        queue<int> q;//queue to store nodes to search and visit 

        visited[start] = true;//since we start here then it is visited
        q.push(start);//add it to the queue

        cout << "BFS Traversal from node " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            //visit all unvisited neighbors
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;//go to the neighbors 
                    q.push(i);//add them to the queue
                }
            }
        }//loop until the queue is empty,meaning everything is visited 

        cout << endl;
    }

    //Depth-First Search from a given node 
    void dfs(int start) {
        bool visited[MAX] = { false };//track if a node is visited so we do not loop in all directions, initially non of them is visited
        stack<int> s;//stack to store nodes to search and visit 

        s.push(start);//add it to the queue

        cout << "DFS Traversal from node " << start << ": ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();//remove the top node, indicate it is visited and add it's neighbors

            //visit the node if it hasn’t been visited
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                //push unvisited neighbors to the stack (in reverse order)
                for (int i = numVertices - 1; i >= 0; i--) {
                    if (adjMatrix[current][i] == 1 && !visited[i]) {
                        s.push(i);//add to stack
                    }
                }
            }
        }//loop until the queue is empty,meaning everything is visited 

        cout << endl;
    }
};

int main() {
    //create a graph with 6 nodes
    Graph g(6);

    //add edges to make the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    //perform BFS and DFS starting from node 0
    g.bfs(0);
    g.dfs(0);

    return 0;
}