
def find_lowest_cost_node(costs):
	lowest_cost = float("inf")
	lowest_cost_node = None
	for node in costs:
		cost = costs[node]
		if cost < lowest_cost and node not in processed:
			lowest_cost = cost
			lowest_cost_node = node

	return lowest_cost_node

graph = {}
graph["start"] = {}
graph["start"]["a"] = 5
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["c"] = 4
graph["a"]["d"] = 2

graph["b"] = {}
graph["b"]["a"] = 8
graph["b"]["d"] = 7

graph["c"] = {}
graph["c"]["d"] = 6
graph["c"]["fim"] = 3

graph["d"] = {}
graph["d"]["fim"] = 1

graph["fim"] = {}

infinity = float("inf")

costs = {}
costs["a"] = 5
costs["b"] = 2
costs["c"] = infinity
costs["d"] = infinity
costs["fim"] = infinity

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["c"] = "a"
parents["d"] = "b"
parents["fim"] = None

processed = []

node = find_lowest_cost_node(costs)  
while node is not None:
	print("node: " + node)
	cost = costs[node]
	print("cost: ",cost)
	neighbors = graph[node]
	for n in neighbors.keys():
		new_cost = cost + neighbors[n]
		if costs[n] > new_cost:
			costs[n] = new_cost
			parents[n] = node

	processed.append(node)
	node = find_lowest_cost_node(costs)

print(costs["fim"])
