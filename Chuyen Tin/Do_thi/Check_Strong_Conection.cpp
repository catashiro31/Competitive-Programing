#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> adjList, int u, vector<bool> &visited) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) DFS(adjList,v,visited);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<int>> adjList(n+1);
	vector<vector<int>> TadjList(n+1);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adjList[u].push_back(v);
		TadjList[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	DFS(adjList,1,visited);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << 0;
			return 0;
		}
	}
	fill(visited.begin(),visited.end(),false);
	DFS(TadjList,1,visited);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	cerr << "\nTime elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
