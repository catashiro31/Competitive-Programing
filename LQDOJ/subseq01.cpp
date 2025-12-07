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
	for (int x : a) if (x >= 0) am = false;
	if (am) {
		cout << *max_element(all(a)) << " " << *max_element(all(a)) << endl;
	} else {
		int sum = 0, cmin = 0;
		int kq1 = 0, kq2 = -1;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			kq2 = max(kq2,sum-cmin);
			cmin = min(cmin,sum);
			if (a[i] >= 0) kq1 += a[i];
		}
		cout << kq1 << " " << kq2 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
