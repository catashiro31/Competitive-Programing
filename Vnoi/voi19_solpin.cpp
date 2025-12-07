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

void solve() {
	int m, n; cin >> m >> n;
	vector<vector<int>> a(m,vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	} 
	vector<vector<int>> prefix(m,vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) prefix[i][j] = a[i][j];
			else if (i == 0) prefix[i][j] = prefix[i][j-1] + a[i][j];
			else if (j == 0) prefix[i][j] = prefix[i-1][j] + a[i][j];
			else prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
		}
	}
	auto cal = [&](int x, int y, int u, int v) {
		if (x == 0 && y == 0) return prefix[u][v];
		else if (x == 0) return prefix[u][v] - prefix[u][y-1];
		else if (y == 0) return prefix[u][v] - prefix[x-1][v];
		return prefix[u][v] - prefix[x-1][v] - prefix[u][y-1] + prefix[x-1][y-1];	
	};
	int q; cin >> q;
	int sx = 0, sy = 0;
	while(q--) {
		int p; cin >> p;
		if (p == 0) {
			int x, y; cin >> x >> y;
			sx += x, sy += y;
		} else {
			int u, v, s, t; cin >> u >> v >> s >> t;
			--u, --v, --s, --t;
			int nu = (u+sy)%m, nv = (v+sx)%n, ns = (s+sy)%m, nt = (t+sx)%n;
			if (nu <= ns && nv <= nt) cout << cal(nu,nv,ns,nt) << endl;
			else if (nu <= ns) cout << cal(nu,nv,ns,n-1) + cal(nu,0,ns,nt) << endl;
			else if (nv <= nt) cout << cal(nu,nv,m-1,nt) + cal(0,nv,ns,nt) << endl;
			else cout << cal(nu,nv,m-1,n-1) + cal(0,0,ns,nt) + cal(nu,0,m-1,nt) + cal(0,nv,ns,n-1)<< endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
