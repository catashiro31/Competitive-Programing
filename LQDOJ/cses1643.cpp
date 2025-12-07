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
	bool am = true;
	for (int i = 0; i < n; i++) if (a[i] >= 0) am = false;
	if (am) {
		cout << *max_element(all(a));
		return;
	}
	int kq = 0, sum = 0, cmin = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		cmin = min(cmin, sum);
		kq = max(kq,sum-cmin);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
