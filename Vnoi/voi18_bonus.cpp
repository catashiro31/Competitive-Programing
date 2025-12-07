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
	int n, k, r, p; cin >> n >> k >> r >> p;
	vector<vector<int>> a(n+1,vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + a[i][j];
		}
	}
	auto gsum = [&](int x, int y, int u, int v) {
		return prefix[u][v] - prefix[u][y-1] - prefix[x-1][v] + prefix[x-1][y-1];	
	};
	vector<vector<pair<int,int>>> gift(k,vector<pair<int,int>>(p));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) cin >> gift[i][j].fi >> gift[i][j].se;
	}
	vector<vector<int>> val(k,vector<int>(p));
	for (int i = 0; i < k; i++) {
		for (int mask = 1; mask < (1<<p); mask++) {
			int cnt = 0;
			pair<int, int> up_current = {n + 1, n + 1};
			pair<int, int> dw_current = {1, 1};
			bool is_valid = true;
			
			for (int j = 0; j < p; j++) {
			    if ((mask >> j) & 1) {
			        cnt++;

			        dw_current.fi = max(dw_current.fi, gift[i][j].fi);
			        dw_current.se = max(dw_current.se, gift[i][j].se);
			
			        up_current.fi = min(up_current.fi, gift[i][j].fi + r - 1);
			        up_current.se = min(up_current.se, gift[i][j].se + r - 1);
			    }
			}
			int _union = -1;
			if (dw_current.fi > up_current.fi || dw_current.se > up_current.se) {
			    _union = 0;
			} else {
			    _union = gsum(dw_current.fi, dw_current.se, up_current.fi, up_current.se);
			}
			val[i][cnt-1] += _union;
		}
	}
	int kq = 0;
	for (int i = 0; i < k; i++) {
		int sum = 0;
		for (int j = 0; j < p; j++) {
			if (j % 2 == 0) sum += val[i][j];
			else sum -= val[i][j];
		}
		kq = max(kq,sum);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
