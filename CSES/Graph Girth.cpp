#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	int kq = INT_MAX;
	for (int i = 0; i < n; i++) {
		vector<int> sp(n,0);
		vector<int> p(n,-1);
		queue<int> q; q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : adjList[u]) {
				if (v == p[u]) continue;
				if (sp[v]) kq = min(kq,sp[u] + sp[v] + 1);
				else {
					p[v] = u, sp[v] = sp[u] + 1;
					q.push(v);
				}
			}
		}
	}
	if (kq == INT_MAX) cout << -1;
	else cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
