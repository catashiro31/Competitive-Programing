#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> adjList, int s, vector<int> status) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		status[s] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			cout << u << " ";
			for (int v : adjList[u]) {
				if (status[v] == 0) {
					status[v] = 1;
					q.push(v);
				}
			}
			status[u] = 2;
		} 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	int s, t; inFile >> s >> t;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	inFile.close();
	vector<int> status(n,0);
	BFS(adjList,s,status);
}
