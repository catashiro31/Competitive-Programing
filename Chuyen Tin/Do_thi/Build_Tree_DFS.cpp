#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adjList;
vector<bool> visited;
vector<pair<int,int>> dfsTreeEdge;
void input() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> n >> m;
	adjList.assign(n+1,vector<int> ());
	visited.assign(n+1,false);
	for (int i = 0; i < m; ++i) {
		int u,v; inFile >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	inFile.close();
}
void DFS(int u) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) {
			dfsTreeEdge.push_back({u,v});
			DFS(v);
		}
	}
} 
void BuildDfsTree() {
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();	
	BuildDfsTree();
	for (auto x : dfsTreeEdge) {
		cout << x.first << " - " << x.second << '\n';
	}
}
