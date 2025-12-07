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

int _find(int u, vector<int> &par) {
	if (par[u] == u) return u;
	return par[u] = _find(par[u], par); 
} 

bool _union(int u, int v, vector<int> &par) {
	int pu = _find(u,par), pv = _find(v,par);
	if (pu == pv) return false;
	if (pu < pv) swap(pu,pv);
	par[pu] = pv;
	return true;
}

void solve() {
	int n, m; cin >> n >> m;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<>> pq;
	for (int i = 0; i < m; i++) {
		int u, v, d; cin >> u >> v >> d;
		--u, --v;
		pq.push({d,{u,v}});
	}
	int kq = 0;
	vector<int> par(n);
	for (int i = 0; i < n; i++) par[i] = i;
	while (!pq.empty()) {
		auto [d,uv] = pq.top(); pq.pop();
		auto [u,v] = uv;
		if (_union(u,v,par)) kq += d; 
	}
	bool c = true;
	for (int i = 0; i < n; i++) if (par[i] != 0) c = false;
	if (c) cout << kq << endl;
	else cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
