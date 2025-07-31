#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> adjList[n];
	vector<int> in(n,0);
	for (int i = 0; i < m; i++) {
		int u,v; cin >> u >> v;
		adjList[u-1].push_back(v-1);
		in[v-1]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
	vector<int> topo_sort;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo_sort.push_back(u);
		for (int v : adjList[u]) {
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	vector<int> dp(n,0);
	for (int u : topo_sort) {
		for (int v : adjList[u]) {
			dp[v] = max(dp[v],dp[u]+1);
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
