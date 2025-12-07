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
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n+1,vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] + a[i][j] - prefix[i-1][j-1];
	}
	int l = 1, r = n, kq = -1;
	while (l <= r) {
		int m = (l+r)/2;
		bool c = true;
		for (int i = 0; i+m <= n; i++) {
			if (!c) break;
			for (int j = 0; j+m <= n; j++) {
				int x = i+m, y = j+m;
				if (prefix[x][y] - prefix[i][y] - prefix[x][j] + prefix[i][j] < k) {
					c = false; 
					break;
				}
			}
		}
		if (c) kq = m, r = m-1;
		else l = m+1; 
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
