#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
		if (x&1) odd++;
		else even++;
	}
	if (odd != n && even != n) {
		sort(all(a));
		for (int x : a) cout << x << " ";
	} else {
		for (int x : a) cout << x << " ";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}