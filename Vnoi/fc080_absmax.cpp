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
	for (int &x : a) cin >> x;
	int cmax = LLONG_MIN, cmin = LLONG_MAX;
	int kq = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		if (i) kq = max({kq,abs(cmax+a[i]), abs(cmin+a[i])});
		cmax = max(cmax,a[i]);
		cmin = min(cmin,a[i]);
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
