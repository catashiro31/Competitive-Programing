#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

int timer = 0;
void dfs(int u, int par, const vector<vector<int>> &adj, vector<int> &sl) {
	int st = timer++;
	for(int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,sl);
	}
	sl[u] = timer - st;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);	
	}
	vector<int> sl(n,0);
	timer = 0;
	dfs(0,-1,adj,sl);
	int kq = 0;
	for (int i = 0; i < n; i++) {
		kq = kq + 1 + (sl[i]>=k ? (n-sl[i]) : 0) + (n-sl[i]>=k ? sl[i] : 0);
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
