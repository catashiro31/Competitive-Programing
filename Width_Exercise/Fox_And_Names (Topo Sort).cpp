#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
bool wrong = false;
void DFS(int u, vector<int> adjList[], vector<int> &visited, vector<int> &topo_sort) {
	visited[u] = 0;
	for (int v : adjList[u]) {
		if (visited[v] == -1) DFS(v, adjList,visited,topo_sort);
		if (visited[v] == 0) wrong = true;
	}
	topo_sort.push_back(u);
	visited[u] = 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<string> xau(n);
	for (string &x : xau) cin >> x;
	vector<int> adjList[26];
	for (int i = 1; i < n; i++) {
		int j = 0;
		while (j < xau[i-1].size() && j < xau[i].size() && xau[i-1][j] == xau[i][j]) {
			j++;
		}
		if (j == xau[i-1].size()) continue;
		else if (j == xau[i].size()) wrong = true;
		adjList[xau[i-1][j]-'a'].push_back(xau[i][j]-'a');
	}
	vector<int> visited(26,-1);
	vector<int> topo_sort;
	for (int i = 25; i >= 0; i--) {
		if (visited[i] == -1) DFS(i,adjList,visited,topo_sort);
	}
	if (wrong) {
		cout << "Impossible";
		return 0;
	}
	reverse(topo_sort.begin(),topo_sort.end());
	for (int vl : topo_sort) cout << (char)(vl+'a');
	return 0;
}
