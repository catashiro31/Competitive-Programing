#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> adjList;
vector<bool> visited;
vector<pair<int,int>> EdgebfsTree;
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
void BFS(int u) {
	queue<int> q;
	visited[u] = true;
	q.push(u);
	while (!q.empty()) {
		int k = q.front(); q.pop();
		for (int v : adjList[k]) {
			if (!visited[v]) {
				EdgebfsTree.push_back({k,v});
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
void BuildTreeBfs() {
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			BFS(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	BuildTreeBfs();
	for (auto x : EdgebfsTree) {
		cout << x.first << " - " << x.second << '\n' ;
	}
}
