#include "bfs.hpp"

bool bfs(Graph g, int source, int target, vector<int> &parent){

    vector<bool> visited(g.nVertices, false);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto &adj : g.adj_list[u]){
            int v = adj.first;
            if (visited[v]==false && adj.second > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[target] == true);
}