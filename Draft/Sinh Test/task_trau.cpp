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
	vector<vector<pair<int,int>>> gift(k,vector<pair<int,int>>(p));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) cin >> gift[i][j].fi >> gift[i][j].se;
	}
	int kq = 0;
	for (int i = 0; i < k; i++) {
		vector<vector<bool>> used(n+1,vector<bool>(n+1,false));
		for (int j = 0; j < p ; j++) {
			auto [x,y] = gift[i][j];
			for (int h = 0; h < r; h++) {
				for (int l = 0; l < r; l++) used[x+h][y+l] = true;
			}
		}
		int val = 0;
		for (int j = 1; j <= n; j++) {
			for (int h = 1; h <= n; h++) {
				if (used[j][h]) val += a[j][h];
			}
		}
		kq = max(kq, val);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("task.inp","r",stdin);
	freopen("task.ans","w",stdout);
	int t = 1;
	while(t--) solve();
}
