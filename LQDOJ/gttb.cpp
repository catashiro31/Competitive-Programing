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
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(all(a));
	for (int i = 1; i < n; i++) a[i] += a[i-1];
	vector<pair<double,int>> arr(n);
	for (int i = 0; i < n; i++) arr[i] = {1.0*a[i]/(i+1),i+1};
	sort(all(arr));
	vector<int> cmax(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) cmax[i] = arr[i].se;
		else cmax[i] = max(arr[i].se,cmax[i-1]);
	}
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		int l = 1, r = n, kq = 0;
		while (l <= r) {
			int m = (l+r)/2;
			if (arr[m-1].fi >= 1.0*k) r = m-1;
			else kq = max(kq,cmax[m-1]), l = m+1;
		}
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
