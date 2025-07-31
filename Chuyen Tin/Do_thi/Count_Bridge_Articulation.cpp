#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adjList;
vector<int> disc, low;
int Bridges = 0, Articulations = 0;
int cnt = 0;
void input() {
	ifstream inFile("C:/Users/Actama/Documents/C++/input.txt");
	inFile >> n >> m;
	adjList.assign(n+1,vector<int> ());
	disc.assign(n+1,0);
	low.assign(n+1,0);
	for (int i = 0; i < m; ++i) {
		int u,v; inFile >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	inFile.close();
}
void DFS(int u, int p) {
    disc[u] = low[u] = ++cnt;
    int children = 0;  // Đếm số con của u trong cây DFS
    for (int v : adjList[u]) {
        if (v == p) continue;  // Bỏ qua cha của u
        if (disc[v] == 0) {  // Nếu v chưa được khám phá
            children++;
            DFS(v, u);
            // Cập nhật giá trị low-link của u
            low[u] = min(low[u], low[v]);
            // Nếu low[v] > disc[u], thì (u, v) là cầu
            if (low[v] > disc[u]) Bridges++;
            // Nếu low[v] >= disc[u], thì u là khớp (nếu u không phải là gốc)
            if (p != 0 && low[v] >= disc[u]) Articulations++;
        } else {
            // Nếu v đã được thăm, cập nhật low-link cho u
            low[u] = min(low[u], disc[v]);
        }
    }
    // Nếu u là gốc và có nhiều hơn 1 con, thì u là khớp
    if (p == 0 && children > 1) Articulations++;
}
void output() {
	cout << "Count of Bridges: " << Bridges << '\n';
	cout << "Count of Articulations: " << Articulations << '\n'; 
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
