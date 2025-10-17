#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
int timer = 1;
void dfs(int u, int par, const vector<vector<int>> &adj, vector<int> &st, vector<int> &en) {
	st[u] = timer++;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,st,en);
	}
	en[u] = timer-1;
}

void update(vector<ll> &BIT, int x, int val) {
	for (; x < BIT.size(); x += x&(-x)) BIT[x] += val;
}

ll getv(const vector<ll> &BIT, int x) {
	ll res = 0;
	for (; x > 0; x -= x&(-x)) res += BIT[x];
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	vector<int> st(n+1), en(n+1);
	dfs(1,0,adj,st,en);
	vector<ll> BIT(n+1,0);
	for (int i = 1; i <= n; i++) update(BIT,st[i],v[i]);
	while(q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, x; cin >> s >> x;
			update(BIT,st[s],x-v[s]);
//			update(BIT,en[s]+1,v[s]-x);
			v[s] = x;
		} else {
			int s; cin >> s;
			cout << getv(BIT,en[s]) - getv(BIT,st[s]-1) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
