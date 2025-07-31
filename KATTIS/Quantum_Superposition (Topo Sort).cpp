#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
void DFS(int u, vector<int> adjList[], vector<bool> &visited, vector<int> &topo) {
	visited[u] = true;
	for (int v : adjList[u]) {
		if (!visited[v]) DFS(v,adjList,visited,topo);
	}
	topo.push_back(u);
}
set<int> Way(vector<int> adjList[], int n) {
	vector<bool> visited(n,false);
	vector<int> topo;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) DFS(i,adjList,visited,topo);
	}
	reverse(topo.begin(),topo.end());
	set<int> way[n];
	way[0] = {0};
	int i = 0;
	while (topo[i]) i++;
	while (i < n) {
		int u = topo[i++];
		for (auto v : adjList[u]) {
			for (auto k : way[u]) {
				way[v].insert(k+1);
			}
		}
	}
	return way[n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n1,n2,m1,m2; cin >> n1 >> n2 >> m1 >> m2;
	vector<int> adjList1[n1];
	for (int i = 0; i < m1; i++) {
		int u,v; cin >> u >> v;
		adjList1[u-1].push_back(v-1);
	}
	vector<int> adjList2[n2];
	for (int i = 0; i < m2; i++) {
		int u,v; cin >> u >> v;
		adjList2[u-1].push_back(v-1);
	}
	set<int> way1 = Way(adjList1,n1);
	set<int> way2 = Way(adjList2,n2);
	set<int> way;
	for (int vl1 : way1) {
		for (int vl2 : way2) way.insert(vl1+vl2);
	}
	int Q; cin >> Q;
	while (Q--) {
		int q; cin >> q;
		if (way.find(q) != way.end()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}