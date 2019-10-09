#ifndef ALGORITHM_GRAPH_HPP
#define ALGORITHM_GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>

class Graph
{
public:
    int nVertices;
    std::vector<std::vector<std::pair<int, int>>> adj_list;
    Graph(int nVertices, int N)
    {
        this->nVertices = nVertices;
        adj_list.resize(N);
    }

    void addEdge(int source, int dest, int weight);
    void printGraph();
    int weight(int u, int v);
};

#endif
