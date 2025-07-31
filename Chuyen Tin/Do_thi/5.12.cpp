#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adjList, int u, vector<bool> &check, vector<int> &kq, vector<int> a) {
	check[u] = true;
	for (int v : adjList[u]) {
		if (!check[v]) {
			DFS(adjList, v, check, kq,a);
		}
	}
	kq.push_back(a[u]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	int n, m; inFile >> n >> m;
	vector<int> a(n);
	for (int &x : a) inFile >> x;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; ++i) {
		int u, v; inFile >> u >> v;
		if (a[u] >= a[v]) adjList[u].push_back(v);
	}
	inFile.close();
	vector<int> kq;
	vector<bool> check(n,false);
	for (int i = 0; i < n; ++i) {
		if (!check[i]) DFS(adjList,i,check,kq,a);
	}
	for (int x : kq) cout << x << " ";
}
