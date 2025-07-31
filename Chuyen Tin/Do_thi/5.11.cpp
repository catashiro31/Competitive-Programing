#include <bits/stdc++.h>
using namespace std;
bool hasCycle(vector<vector<int>> adjList, int u, vector<bool> &visited, int parent) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) {
			if (hasCycle(adjList,v,visited,u)) return true;
		} else if (v != parent) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	vector<vector<int>> adjList(n);
	for (int i = 0;  i < m; ++i) {
		int u,v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	int s; inFile >> s;
	inFile.close();
	vector<bool> visited(n,false);
	if (hasCycle(adjList,s,visited,-1)) cout << "HasCycle";
	else cout << "NoHasCycle";
}
