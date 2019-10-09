#ifndef ALGORITHM_BFS_HPP
#define ALGORITHM_BFS_HPP

#include "../graph/Graph.hpp"
#include <queue>

using namespace std;

bool bfs(Graph g, int source, int target, vector<int> &parent);

#endif
