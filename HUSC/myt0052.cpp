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
	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int l = 0, r = 1e18;
	int kq = 0;
	while (l <= r) {
		int m = (l+r)/2;
		int sl = 0;
		for (int i = 0; i < n; i++) {
			sl += m/a[i];
			if (sl >= t) break;
		}
		if (sl >= t) kq = m, r = m-1;
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
