#include "fordfulkerson.hpp"

using namespace std;

int ford_fulkerson(Graph G, int src, int target){
    Graph residual(G.nVertices, G.nVertices);

    for (int i = 0; i < residual.nVertices; ++i) {
        for (int j = i; j < residual.nVertices; ++j) {
            residual.addEdge(i, j, 0);
            if(i!=j)
                residual.addEdge(j, i, 0);
        }
    }

    // init flow
    for (int u = 0; u < G.nVertices; u++)
        for (auto & adj : G.adj_list[u])
            residual.adj_list[u][adj.first].second = adj.second;

    vector<int> parent(residual.nVertices, 0);

    int max_flow = 0;

    while(bfs(residual, src, target, parent)){
        int path_flow = numeric_limits<int>::max();

        // find path max flow
        int v = target;
        while (v!=src) {
            int u = parent[v];

            path_flow = min(path_flow, residual.weight(u, v));

            v = parent[v];
        }

        // update residual graph
        v = target;
        while (v != src) {
            int u = parent[v];

            residual.adj_list[u][v].second -= path_flow;

            residual.adj_list[v][u].second += path_flow;
            v = parent[v];
        }

        max_flow += path_flow;
    }

    for (auto &adj : residual.adj_list){
        for (int i = 0; i < residual.nVertices; ++i) {
            printf("%4d", adj[i].second);
        }
        cout << endl;
    }

    return max_flow;
}