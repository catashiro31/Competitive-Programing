#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	//	Ma tran ke
	int n; inFile >> n;
	vector<vector<int>> adjMatrix1(n,0);
	int m; inFile >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjMatrix1[u][v] = 1;
	}
	// Danh sach ke
	int n, m; inFile >> n >> m;
	vector<vector<int>> adjList1(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	inFile.close();
	// Ma tran chuyen vi
	vector<vector<int>> adjMatrix2(n,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adjMatrix1[i][j] == 1) adjMatrix2[j][i] = 1;
		}
	}
	// Danh sach ke chuyen vi
	vector<vector<int>> adjList2(n);
	for (int i = 0; i < n; ++i) {
		for (int v : adjList1[i]) adjList2[v].push_back(i);
	}
}
