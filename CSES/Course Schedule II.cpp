#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	set<int> adjList[n];
	vector<int> indegree(n,0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adjList[u-1].insert(v-1);
		indegree[v-1]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!indegree[i]) q.push(i);
	}
	vector<int> topo_sort;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo_sort.push_back(u);
		for (int v : adjList[u]) {
			indegree[v]--;
			if (!indegree[v]) q.push(v);
		}
	}
//	for (int vl : topo_sort) cout << vl << " ";
	vector<int> priority(n,0);
	int tmp = 0;
	for (int u : topo_sort) {
		if (priority[u] == 0) priority[u] = tmp;

		for (int v : adjList[u]) priority[v] = priority[u]+1;
	}
	vector<pair<int,int>> kq;
	for (int i = 0; i < n; i++) {
		kq.push_back({priority[i],i});
	}
	sort(kq.begin(),kq.end());
	for (auto x : kq) cout << x.second+1 << " ";
	return 0;
}
