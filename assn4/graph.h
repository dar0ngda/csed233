#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#define NodeMaxCount 101
#define INF 2147483647 
using namespace std;

/////////////////////////////////////////////////////////
///  TODO: Add Your Struct or Functions if required /////
typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct queue {
    int count;
    node* front;
    node* rear;
}queue;

typedef struct {
    int from;
    int to;
    int weight;
}edge;
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

class Graph{
public:
    Graph() {
        for (int i = 0; i < NodeMaxCount; i++) {
            for (int j = 0; j < NodeMaxCount; j++) {
                adjmtrx[i][j] = 0;
            }
            nodes[i] = 0;
        }
        num_nodes = 0;
    };
    ~Graph() { };

    string DFS();
    string BFS();
    
    int addDirectedEdge(string nodeA, string nodeB);
    int addDirectedEdge(string nodeA, string nodeB, int weight);
    int addUndirectedEdge(string nodeA, string nodeB);
    int addUndirectedEdge(string nodeA, string nodeB, int weight);

    int countUndirectedCycle();
    string getTopologicalSort();
    int countDirectedCycle();
    string getShortestPath(string source, string destination);
    string getAllShortestPaths(); 
    int primMST(ofstream &, string startNode);
    int kruskalMST(ofstream &);


private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int num_nodes;
    int nodes[NodeMaxCount];
    int adjmtrx[NodeMaxCount][NodeMaxCount];
    void _DFS(string& answer, bool* visited, int c);
    void _BFS(string& answer, bool* visited, queue& q, int c);
    void countcycle(int& count, bool* visited, int c, int parent);
    int minweight(int* distance, bool* visited);
    int safe_add(int a, int b);
    int find_set(int node, int* parent);
    void union_set(int, int, int*, int*);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
