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
	int n, m, q; cin >> n >> m >> q;
	vector<vector<long>> floyd(n,vector<long>(n,LONG_MAX));
	for (int i = 0; i < n; i++) floyd[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		long w; cin >> w;
		--u, --v;
		floyd[u][v] = min(floyd[u][v],w);
	}
	for (int k = 0; k < n; k++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (floyd[u][k] == LONG_MAX || floyd[k][v] == LONG_MAX) continue;
				floyd[u][v] = min(floyd[u][v],floyd[u][k] + floyd[k][v]);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		--u, --v;
		if (floyd[u][v] == LONG_MAX) cout << -1 << endl;
		else cout << floyd[u][v] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
