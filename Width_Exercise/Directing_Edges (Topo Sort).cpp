#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
bool Wrong;
void DFS(vector<int> adjList[], vector<int> &visited, int u, vector<int> &topo_sort) {
	visited[u] = 0;
	for (int v : adjList[u]) {
		if (visited[v] == -1) DFS(adjList,visited,v,topo_sort);
		if (visited[v] == 0) Wrong = true;
	}
	visited[u] = 1;
	topo_sort.push_back(u);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		Wrong = false;
		int n, m; cin >> n >> m;
		vector<pair<int,int>> edges;
		vector<int> adjList[n];
		for (int i = 0; i < m; i++) {
			int status, u, v; cin >> status >> u >> v;
			if (status) adjList[u-1].push_back(v-1);
			edges.push_back({u-1,v-1});
		}
		vector<int> visited(n,-1);
		vector<int> topo_sort;
		for (int i = 0; i < n; i++) {
			if (visited[i] == -1) DFS(adjList,visited,i,topo_sort);
		}
		if (Wrong) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		reverse(topo_sort.begin(),topo_sort.end());
		vector<int> pos(n);
		for (int i = 0; i < n; i++) pos[topo_sort[i]] = i;
		for (auto &x : edges) {
			if (pos[x.first] > pos[x.second]) swap(x.first,x.second);
			cout << x.first+1 << " " << x.second+1 << endl; 
		}
	}
	return 0;
}
