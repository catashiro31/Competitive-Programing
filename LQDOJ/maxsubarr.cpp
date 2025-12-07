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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int l = 1, r = n, kq = -1;
	while (l <= r) {
		int m = (l+r)/2;
		bool c = true;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (i < m-1) continue; 
			if (sum >= k) c = false;
			sum -= a[i-m+1]; 
		}
		if (c) kq = m, l = m+1;
		else r = m-1;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
