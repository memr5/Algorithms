#include "Graph.hpp"
using namespace std;
void Graph::addEdge(int source, int dest, int weight) {
    adj_list[source].push_back(make_pair(dest, weight));
}

void Graph::printGraph() {
    cout<< "(u, v, weight)\n";
    int i = 0;
    for(auto &adj : adj_list){
        for(auto &edge : adj){
            printf("(%d, %d, %d)\n", i, edge.first, edge.second);
        }
        i++;
    }
    cout<<endl;
}

int Graph::weight(int u, int v) {

    for (auto &adj : this->adj_list[u]){
        if (adj.first == v)
            return adj.second;
    }

    return numeric_limits<int>::max();
}
