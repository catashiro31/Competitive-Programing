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

vector<vector<int>> lca(MAXN,vector<int>(19,0));
vector<vector<int>> lca_max(MAXN,vector<int>(19,0));
void dfs(int u, int par, int val,const vector<vector<int>> &adj, vector<int> &degree, const vector<int> &w) {
	lca_max[u][0] = val, lca[u][0] = par;
	for (int i = 1; i < 19; i++) lca[u][i] = lca[lca[u][i-1]][i-1];
	for (int i = 1; i < 19; i++) lca_max[u][i] = max(lca_max[u][i-1],lca_max[lca[u][i-1]][i-1]);
	for (int v : adj[u]) {
		if (v == par) continue;
		degree[v] = degree[u] + 1;
		dfs(v,u,max(w[u],w[v]),adj,degree,w);
	}
}

int getlca_max(int u, int v,const vector<int> &degree) {
	if (degree[u] > degree[v]) swap(u,v);
	int dif = degree[v] - degree[u];
	int kq = -1;
	for (int i = 0; i < 19; i++) {
		if ((dif>>i) & 1) {
			kq = max(kq,lca_max[v][i]);
			v = lca[v][i];	
		}
	} 
	if (u == v) return kq;
	for (int i = 18; i >= 0; i--) {
		if (lca[u][i] == lca[v][i]) continue;
		kq = max(kq,lca_max[u][i]);
		kq = max(kq,lca_max[v][i]);
		u = lca[u][i], v = lca[v][i];
	}
	kq = max(kq,lca_max[u][0]);
	kq = max(kq,lca_max[v][0]);
	return kq;
}

void solve() {
	int n; cin >> n;
	vector<int> w(n+1,0), degree(n+1,0);
	vector<vector<int>> adj(n+1);
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	dfs(1,0,max(w[0],w[1]),adj,degree,w);
	int k; cin >> k;
	vector<vector<pair<int,int>>> delivery(n+1);
	vector<int> bonus(k);
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v;
		delivery[u].psb({v,i});
		bonus[i] = getlca_max(u,v,degree);
	}
	vector<int> kq(n+1,LLONG_MIN);
	kq[1] = 0;
	queue<pair<int,int>> q;
	q.push({1,-1});
	while(!q.empty()) {
		auto [u,id] = q.front(); q.pop();
		for (auto [v,ma] : delivery[u]) {
			if (ma <= id) continue;
			if (kq[v] < kq[u] + bonus[ma]) {
				kq[v] = kq[u] + bonus[ma];
				q.push({v,ma});
			}
		}
	}
	cout << *max_element(kq.begin(),kq.end());
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("SHIP.inp","r",stdin);
//	freopen("SHIP.out","w",stdout);
	int t = 1;
	while(t--) solve();
}

