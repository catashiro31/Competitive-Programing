#include<bits/stdc++.h>
using namespace std;

void solve() {
	int x, n; cin >> x >> n;
	if (n&1) cout << x << endl;
	else cout << 0 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}