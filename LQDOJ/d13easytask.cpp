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
	vector<bool> c_snt(1000005,true);
	c_snt[0] = false, c_snt[1] = false;
	for (int i = 2; i*i <= 1000005; i++) {
		if (!c_snt[i]) continue;
		for (int j = i*i; j < 1000005; j+=i) c_snt[j] = false;
	}
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int kq = LLONG_MIN, sum = 0, cmin = 1e12;
	for (int i = 0; i < n; i++) {
		if (c_snt[i+1]) cmin = min(cmin,sum);
		sum += a[i];
		if (c_snt[i+1]) kq = max(kq,sum-cmin);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
