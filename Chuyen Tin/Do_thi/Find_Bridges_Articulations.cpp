#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adjList;
vector<int> disc, low;
vector<pair<int,int>> Bridges;
set<int> Articulations;
int cnt = 0;
void input() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> n >> m;
	adjList.assign(n+1,vector<int> ());
	disc.assign(n+1,0);
	low.assign(n+1,0);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	inFile.close();
}
void DFS(int u, int p) {
	disc[u] = low[u] = ++cnt;
	int children = 0;
	for (int v : adjList[u]) {
		if (v == p) continue;
		if (disc[v] != 0) {
			low[u] = min(low[u],disc[v]);
		} else {
			children++;
			DFS(v,u);
			low[u] = min(low[u],low[v]);
			if (low[v] > disc[u]) Bridges.push_back({u,v});
			if (p != 0 && low[v] >= disc[u]) Articulations.insert(u);
		}
	}
	if (p == 0 && children > 1) Articulations.insert(u);
}
void output() {
	cout << "Bridges: \n";
	for (auto x : Bridges) {
		cout << "( " << x.first << ", " << x.second << ")  ";
	}
	cout << '\n';
	cout << "Articulations: \n";
	for (int x : Articulations) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	for (int i = 1; i <= n; ++i) {
		if (disc[i] == 0) DFS(i,0);
	}
	output();
}
