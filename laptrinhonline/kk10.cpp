#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void init(int n, vector<int> &parent, vector<int> &sz) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sz[i] = 1;
		}
	}
	
int Find(int u, vector<int> &parent) {
	if (parent[u] == u) return u;
	else {
		return parent[u] = Find(parent[u],parent);
	}
}
	
bool Union(int u, int v, vector<int> &parent, vector<int> &sz) {
	u = Find(u,parent);
	v = Find(v,parent);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u,v);
	sz[u] += sz[v];
	parent[v] = u;
	return true;
}
void solve() {
	int n, m, q; cin >> n >> m >> q;
	
	vector<pair<int,int>> e;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		e.pb({--u,--v});
	}
	
	vector<bool> n_used(m,false);
	vector<pair<int,int>> qr;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		qr.pb({--u,--v});
		n_used[u] = true;
	}
	
	vector<int> parent(n), sz(n);
	init(n,parent,sz);
	
	for (int i = 0; i < m; i++) {
		if (n_used[i]) continue;
		Union(e[i].fi,e[i].se,parent,sz);
	}
	
	vector<int> kq(q);
	for (int i = q-1; i >= 0; i--) {
		kq[i] = sz[Find(qr[i].se,parent)];
		Union(e[qr[i].fi].fi,e[qr[i].fi].se,parent,sz);
	}
	
	for (int i = 0; i < q; i++) cout << kq[i] << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}