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
	int n, m, q; cin >> n >> m >> q;
	vector<vector<ll>> d(n,vector<ll> (n,1e18));
	for (int i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		--u, --v;
		d[u][v] = min(d[u][v],w);
		d[v][u] = min(d[v][u],w);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
				d[j][i] = d[i][j];
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		--u, --v;
		if (u == v) cout << 0 << endl;
		else if (d[u][v] == 1e18) cout << -1 << endl;
		else cout << d[u][v] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
