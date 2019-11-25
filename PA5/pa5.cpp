#include <iostream>
#include <list>
using namespace std;


class Graph
{
    int numVertices;
    list<int> *adjLists;
    
public:
    Graph(int V);
    void addEdge(int start, int end);
    printGraph();
};

Graph::Graph(int vertices){
	numVertices = vertices;
	adjLists = new list<int>[vertices];
}
void Graph::addEdge(int start, int end){
	adjLists[start].push_front(end); 
}
void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (int i = 0; i < adj.size(); i++){
        	cout << adj[i];
           	cout << "-> ";
        }
        printf("\n");
    }
}


int main(){
	Graph test(4);
	test.addEdge(0,1);
	test.addEdge(0,2);
	test.addEdge(1,2);
	test.addEdge(2,3);

	return 0;
}