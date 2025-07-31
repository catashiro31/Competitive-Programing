#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> adjList, int s, vector<bool> Check) {
	queue<int> q;
	q.push(s);
	Check[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adjList[u]) {
			if (!Check[v]) {
				cout << u << "," << v << " ";
				Check[v] = true;
				q.push(v);
			}
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
		int u,v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	inFile.close();
	vector<bool> Check(n,false);
	BFS(adjList,s,Check);
}
