#include <bits/stdc++.h>
using namespace std;
void caculate(const vector<vector<int>> adjList, int n, int v) {
	int odeg = adjList[v].size();
	int ideg = 0;
	for (int i = 0; i < n; ++i) {
		for (int u : adjList[i]) {
			if (u == v) ideg++;
		}
	}
	cout << odeg << " " << ideg;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n,m; inFile >> n >> m;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	int v; inFile >> v;
	inFile.close();
	caculate(adjList,n,v);
}
