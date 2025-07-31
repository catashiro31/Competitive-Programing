#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	vector<vector<int>> adjList1(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList1[u].push_back(v);
	}
	inFile.close();
	vector<vector<int>> adjList2(n);
	vector<bool> mark(n,true);
	for (int i = 0; i < n; i++) {
		for (int v : adjList1[i]) {
			if (mark[v]) {
				adjList2[i].push_back(v);
				mark[v] = false;
			}
		}
		for (int j = 0; j < n; j++) mark[j] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int v : adjList2[i]) cout << v << " ";
		cout << '\n';
	}
}
