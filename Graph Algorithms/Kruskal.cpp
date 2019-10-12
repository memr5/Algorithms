#include <bits/stdc++.h>
using namespace std;
class Edge 
{
public:
    int src, dest, weight;
};

class subset
{
public:
    int parent;
    int rank;
};

class Graph {
public:
    int V, E;
    Edge *edge;

    Graph(int v, int e);
    void KruskalMST();
    void Union(subset subsets[], int x, int y);
};

Graph::Graph(int v, int e) {
    V = v;
    E = e;
    edge = new Edge[e];
}

int find (subset subsets[], int i) {
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}

int myComp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void Graph::KruskalMST() {
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(edge, E, sizeof(edge[0]), myComp);

    cout << "After sort << " << endl;
    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        Edge next_edge = edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "MST: ";
    for (int i = 0; i < e; i++) {
        cout << result[i].src << "--" << result[i].dest << " " << result[i].weight << endl;
    }
    return;
}

void Graph::Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  

int main() {

    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph* graph = new Graph(V, E);
  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;  
  
    graph->KruskalMST();  
  
    return 0;  
}  

