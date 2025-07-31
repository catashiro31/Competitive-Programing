#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	// Ma tran ke
	int n, m; inFile >> n >> m;
	vector<vector<int>> adjMatrix1(n,vector<int> (n,0));
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		adjMatrix1[u][v] = 1;
	}
	// Danh sach ke
//	int n, m; inFile >> n >> m;
//	vector<vector<int>> adjList1(n);
//	for (int i = 0; i < m; ++i) {
//		int u, v; inFile >> u >> v;
//		adjList1[u].push_back(v);
//	}
	inFile.close();
	// Ma tran ke
	vector<vector<int>> adjMatrix2(n,vector<int> (n,0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int w = 0; w < n; ++w) {
				if (adjMatrix1[i][w] && adjMatrix1[w][j]) adjMatrix2[i][j] = 1; 
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << adjMatrix2[i][j] << " ";
		cout << '\n';
	}
	// Danh sach ke
//	vector<vector<int>> adjList2(n);
//	for (int u = 0; u < n; ++u) {
//		for (int w : adjList1[u]) {
//			for (int v : adjList1[w]) {
//				if (u != v) adjList2[u].push_back(v);
//			}
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int v : adjList2[i]) cout << v << " ";
//		cout << '\n';
//	}
}
