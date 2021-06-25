#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int max_depth = 0;

void find_depth(vector<int> adj[], vector<bool>& visited, int start, int depth) {
	visited[start] = true;

	max_depth = max(max_depth, depth);

	for (auto i : adj[start]) {
		std::cout << "i " << i;
		if (!visited[i])
		find_depth(adj, visited, i, depth + 1);
	}
}

void dfs(vector<int> adj[], int start, vector<bool>& visited, vector<int>& store_min_elements, int depth) {
	visited[start] = true;

	store_min_elements[depth] = min(store_min_elements[depth], start);

	for (auto i : adj[start]) {
		if (!visited[i])
			dfs(adj, i, visited, store_min_elements, depth + 1);
	}
}

void minSum_depth(vector<int> adj[], int start, int total_nodes) {
	vector<bool> visited(total_nodes, false);

	find_depth(adj, visited, start, 0);

	fill(visited.begin(), visited.end(), false);

	vector<int> store_min_elements(max_depth + 1, INT_MAX);

	dfs(adj, start, visited, store_min_elements, 0);

	int min_sum = 0;

    // Calculation of minimum sum
    for (int i = 0;
        i < store_min_elements.size();
        i++) {
        min_sum += store_min_elements[i];
    }

	cout << min_sum << endl;
}

int main() {
	int V = 7, start = 0;

	vector<int> adj[V];
	addEdge(adj, 0, 0);
	addEdge(adj, 0, 0);
	addEdge(adj, 0, 0);
	addEdge(adj, 1, 0);
	addEdge(adj, 2, 0);
	addEdge(adj, 3, 0);

	minSum_depth(adj, start, V);
}