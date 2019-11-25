/*
 * C++ Program to Implement Adjacency List
 */
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
 
/*
 * Adjacency List Node
 */ 
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
/*
 * Adjacency List
 */  
struct AdjList
{
    struct AdjListNode *head;
};
 
/*
 * Class Graph
 */ 
class Graph
{
    private:
        int V;
        struct AdjList* array;
    public:
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        }
        /*
         * Creating New Adjacency List Node
         */ 
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
        /*
         * Adding Edge to Graph
         */ 
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        /*
         * Print the graph
         */ 
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
};
 
/*
 * Main
 */ 
int main()
{


    string line;
      ifstream myfile ("graph.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          cout << line << '\n';
        }
        myfile.close();
      }

      else cout << "Unable to open file"; 

      /*
    ifstream infile("graph.txt");
    
    int vertices, edges, source, destination, weight;
    infile >> vertices >> edges;

    cout << "v: " << vertices << "e: " << edges << endl;

    Graph gh(vertices);

    for (int i = 1; i <= edges; i++){
        cout << "HI" << endl;
        infile>>source>>destination>>weight;
        cout << source << destination << weight << endl;
        gh.addEdge(source,destination);
    }

    /*
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);
    */
    // print the adjacency list representation of the above graph
    //gh.printGraph();
    
    return 0;
}
