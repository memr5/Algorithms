#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
private:
    int Vertices;
    list<int> *adj;
    void recursiveDFSUtil(int v, bool visited[]);

public:
    Graph(int v);
    ~Graph();
    void addEdge(int v, int w);
    void iterativeDFS(int v);
    void recursiveDfs(int v);

};

Graph::Graph(int v) {
    Vertices = v;
    adj = new list<int>[Vertices];
}
Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::iterativeDFS(int v) {
    stack<int> st;
    bool visited[Vertices];
    for (auto &it : visited) {
        it = false;
    }
    st.push(v);
    while (st.empty() == false) {
        int x = st.top();
        st.pop();

        cout << "Reached node" << x << endl;

        if (visited[x] == false) {
            visited[x] = true;
            for (auto it : adj[x]) {
                if (visited[it] == false) {
                    st.push(it);
                }
            }
        }
    }
}

void Graph::recursiveDfs(int v) {
    bool *visited = new bool[Vertices];
    for (int i = 0; i < Vertices; i++) {
        visited[i] = false;
    }
    recursiveDFSUtil(v, visited);
    delete[] visited;
}

void Graph::recursiveDFSUtil(int v, bool *visited) {
    visited[v] = true;
    cout << "Reached node " << v << endl;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        if (visited[*it] == false) {
            recursiveDFSUtil(*it, visited);
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << "Running recursive DFS" << endl;
    g.recursiveDfs(2);

    cout << "Running iterative DFS" << endl;
    g.iterativeDFS(2);

    return 0;
}