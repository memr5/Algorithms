#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int Vertices;
    list<int> *adj;

public:
    Graph(int v);
    ~Graph();
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int v) {
    Vertices = v;
    adj = new list<int>[v];
}
Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool visited[Vertices];
    for (int i = 0; i < Vertices; i++) {
        visited[i] = false;
    }
    visited[s] = true;

    cout << s << " ";
    queue<int> q; 
    q.push(s);
    while (q.empty() == false) {
        int x = q.front();
        q.pop();

        for (auto it : adj[x]) {
            if (visited[it] == false) {
                visited[it] = true;
                q.push(it);

                cout << it << " ";
            }
        }
    }
    cout << endl;
}

int main() {

    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.BFS(0);


    return 0;
}