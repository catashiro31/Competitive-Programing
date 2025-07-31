#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	int city_num, flight_num;
	std::cin >> city_num >> flight_num;

	vector<vector<int>> flights(city_num);
	vector<vector<int>> back_edge(city_num);
	for (int i = 0; i < flight_num; i++) {
		int a, b;
		std::cin >> a >> b;
		flights[--a].push_back(--b);
		back_edge[b].push_back(a);
	}

	// Use Kahn's algorithm to do a topological sort
	vector<int> in_degree(city_num);
	for (const vector<int> &nodes : flights) {
		for (int node : nodes) { in_degree[node]++; }
	}

	std::queue<int> queue;
	for (int i = 0; i < city_num; i++) {
		if (in_degree[i] == 0) { queue.push(i); }
	}
	vector<int> top_sort;
	while (!queue.empty()) {
		int curr = queue.front();
		queue.pop();
		top_sort.push_back(curr);
		for (int next : flights[curr]) {
			if (--in_degree[next] == 0) { queue.push(next); }
		}
	}
	for (int x : top_sort) cout << x << " ";
}