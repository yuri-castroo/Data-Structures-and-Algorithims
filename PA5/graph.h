#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "heap.h"

using namespace std;

class Edge;

class Vertex
{
public:
	int data;
	bool marked;
	vector<Edge *> edges;
	float d;
	Vertex *parent;
	Heap<Vertex>::Locator locator;

	Vertex(int newData):data(newData){}

	bool operator < ( const Vertex &v ) const 
	{ 
		// implement me
		return true;
	}
};

class Edge{
public:
	Vertex *src, *dest;
	float weight;

	Edge ( Vertex *src, Vertex *dest, float newWeight ) :src ( src ),dest ( dest ), weight ( newWeight ) { }
};

// you should implement the adjacency list data structure
struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};
 
/*
 * Adjacency List
 */  
struct AdjList{
    struct AdjListNode *head;
};



class Graph{
protected:
	vector<Vertex *> verts;
	vector<Edge *> edges;
	int V;
    struct AdjList* array;
public:
	Graph(int V){
		this->V = V;
        array = new AdjList [V];
        for (int i = 0; i < V; ++i){
        	array[i].head = NULL;
        }
	}

	~Graph ( void ){
		// implement me
	}

	Vertex *insertVertex (int data){
		//!!!!!!!!!!!!!!!!!!!
		//int newVertex = Verrtex *newVertex(data);
		//return newVertex;
	}

	void insertEdge ( Vertex *src, Vertex *dest, float weight ){
		AdjListNode* newNode = newAdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
        newNode = newAdjListNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
	}

	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal ){
		// implement me
	}

	void printGraph(){
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

#endif
