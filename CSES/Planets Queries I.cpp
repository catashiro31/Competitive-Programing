#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, q; cin >> n >> q;
	vector<vector<int>> par(31,vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		par[0][i] = x;
	}
	for (int k = 1; k < 31; k++) {
		for (int i = 1; i <= n; i++) par[k][i] = par[k-1][par[k-1][i]];
	}
	while (q--) {
		int u, k; cin >> u >> k;
		for (int i = 30; i >= 0; i--) {
			if ((1<<i)&k) u = par[i][u];
		}
		cout << u << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
