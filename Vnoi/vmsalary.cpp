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

vector<int> segtree[4*MAXN];
void build(int id, int l, int r, const vector<pair<int,int>> &arr) {
	if (l == r) {
		segtree[id].psb(arr[l-1].se);
		return;
	}
	int m = (l+r)>>1;
	build(id<<1,l,m,arr);
	build(id<<1|1,m+1,r,arr);
	
    segtree[id].resize(segtree[id<<1].size() + segtree[id<<1|1].size());
	merge(all(segtree[id<<1]), all(segtree[id<<1|1]), segtree[id].begin());
}

int query(int id, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) {
        auto it = lower_bound(all(segtree[id]), val);
        return (it - segtree[id].begin());
	}
	int m = (l+r)>>1;
	return query(id<<1,l,m,u,v,val) + query(id<<1|1,m+1,r,u,v,val);
}

int timer = 1;
void dfs(int u, int par, const vector<vector<int>> &adj, vector<int> &st, vector<int> &en) {
	st[u] = timer++;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u,adj,st,en);
	}
	en[u] = timer-1;
}

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> c(n);
	cin >> c[0];
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		--x, c[i] = y;
		adj[i].psb(x);
		adj[x].psb(i);
	}
	vector<int> st(n), en(n);
	dfs(0,-1,adj,st,en);
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++) arr[i] = {st[i],c[i]};
	sort(all(arr));

	build(1,1,n,arr);

	int kq = 0;
	for (int i = 0; i < n; i++) {
		int l = st[i]+1, r = en[i];
		if (l > r) continue;
		
		int res = query(1,1,n,l,r,c[i]);
		kq += res * (res-1) / 2;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}