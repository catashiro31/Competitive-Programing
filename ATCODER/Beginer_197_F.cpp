#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
void solve() {
	int n, m; cin >> n >> m;
	vector<int> adj[26][n];
	set<int> dr[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		char c; cin >> c;
		dr[u].insert(v);
		dr[v].insert(u);
		adj[c-'a'][u].psb(v);
		adj[c-'a'][v].psb(u);
	}
	vector<vector<int>> d(n,vector<int>(n,0));
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	queue<pair<int,int>> q;
	q.push({0,n-1});
	vis[0][n-1] = 1;
	while (!q.empty()) {
		auto [u1,u2] = q.front(); q.pop();
		if (u1 == u2) continue;
		if (dr[u1].count(u2)) continue;
		for (int i = 0; i < 26; i++) {
			for (auto v1 : adj[i][u1]) {
				for (auto v2 : adj[i][u2]) {
					if (!vis[v1][v2]) {
						vis[v1][v2] = 1;
						d[v1][v2] = 2 + d[u1][u2];
						q.push({v1,v2});
					}
				}
			}
		} 
	}
	int kq = INT_MAX;
	for (int u = 0; u < n; u++) {
		if (vis[u][u]) kq = min(kq,d[u][u]);
		for (auto v : dr[u]) {
			if (vis[u][v]) kq = min(kq,d[u][v] + 1);
		}
	}
	if (kq == INT_MAX) cout << -1;
	else cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
