#include <bits/stdc++.h>
using namespace std;

string find_lowest_cost_node(map <string, int> costs, set <string> processed)
{
	int lowest_cost = 1000000000;
	string lowest_cost_node;

	map<string, int>::iterator it = costs.begin();
	for (;it != costs.end(); it++)
	{
		int cost = costs[it->first]; 
		if (cost < lowest_cost && processed.find(it->first) == processed.end() )
		{
			lowest_cost = cost;
			lowest_cost_node.clear();
			lowest_cost_node = it->first; 
		}
	}
	
	return lowest_cost_node;
}


int main(int argc, char const *argv[])
{
	map < string, map<string, int> > graph;
 	map <string, int> costs;
 	map <string, string> parents;
	set <string> processed;
	int infinity = INT_MAX;

	graph["start"]["a"] = 6;
	graph["start"]["b"] = 2; 
	graph["a"]["fim"] = 1; 
	graph["b"]["a"] = 3;
	graph["b"]["fim"] = 5;
	graph["fim"]["fim"] = 0;
	costs["a"] = 6;
	costs["b"] = 2;
	costs["fim"] = infinity;
	parents["a"] = "start";
	parents["b"] = "start";
	parents["fim"] = "NULL";
	
	string node = find_lowest_cost_node(costs,processed);
	while (!node.empty())
	{
		int cost = costs[node];
		map<string, int> neighbors (graph[node].begin(), graph[node].end());
		map<string, int>::iterator it = neighbors.begin();
		for (;it != neighbors.end(); it++)
		{
			int new_cost = cost + neighbors[it->first];
			if (costs[it->first] > new_cost)
			{
				costs[it->first] = new_cost;
				parents[it->first] = node;
			}
		}

		processed.insert(node);
		node = find_lowest_cost_node(costs,processed);
	}

	cout << costs["fim"] << endl;

	return 0;
}