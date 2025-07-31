#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> adjList, int s, vector<bool> check) {
	stack<int> stk;
	stk.push(s);
	check[s] = true;
	while (!stk.empty()) {
		int u = stk.top();
		stk.pop();
		cout << u << " ";
		for (int v : adjList[u]) {
			if (!check[v]) {
				check[v] = true;
				stk.push(v);
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
		int u, v; inFile >> u >> v;
		adjList[u].push_back(v);
	}
	inFile.close();
	vector<bool> check(n,false);
	DFS(adjList,s,check);
}
