#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 500005
#define endl '\n'

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		adj[u].psb({v,c});
		adj[v].psb({u,c});
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
	vector<pair<int,int>> kq(n,{0,0});
	pq.push({-1,{0,0}});
	while (!pq.empty()) {
		auto [d,u_sl] = pq.top(); pq.pop();
		auto [u,sl] = u_sl;
		if (kq[u].fi-sl > 0 && kq[u].fi-sl > kq[u].se-d) continue;
		for (auto [v,c] : adj[u]) {
			if (c <= d) continue;
			
			pq.push({c,{v,sl+1}});
		}
	}
	for (auto [sl,c] : kq) cout << sl << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
