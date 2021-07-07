#ifndef ALGORITHM_FORDFULKERSON_HPP
#define ALGORITHM_FORDFULKERSON_HPP

#include <limits>
#include <queue>
#include "../graph/Graph.hpp"
#include "../bfs/bfs.hpp"

int ford_fulkerson(Graph G, int src, int target);

#endif
