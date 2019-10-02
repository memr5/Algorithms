#include <iostream>
#include <algorithm>
#include <vector>

/*
	Iterative top-down implementation of the 0-1 Knapsack problem
 */

int main() {
	int capacity, n_items, weight, benefit, max_benefit = 0;

	std::cin >> capacity >> n_items;

	// DP array that stores the benefit associated with the knapsack of capacity 'i' 
	std::vector<int> knapsack(capacity + 1, -1);

	// Associates 0 to the knapsack with no capacity
	knapsack[0]=0;

	// Iterative execution of combining each of the n items using exactly one of each
	for (int i = 0; i < n_items; i++) {
		std::cin >> weight >> benefit;

		// Check which of the "possible" knapsacks can store the i-th item
		for (int j = capacity - weight; j >= 0; j--) {
			if (knapsack[j] != -1) {
				/* Stores the maximum of adding an item on the smaller knapsack
				and the previously filled knapsack in its respective position*/
				knapsack[j + weight] = std::max(knapsack[j] + benefit, knapsack[j + weight]);
			}
		}
	}

	// Iterate one last time on the array to find the maximum possible benefit
	for (int j = 1; j <= capacity; j++) {
		max_benefit = std::max(max_benefit, knapsack[j]);
	}

	std::cout << max_benefit << std::endl;
}