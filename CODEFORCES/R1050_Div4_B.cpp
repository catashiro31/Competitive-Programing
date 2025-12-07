#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, x, y; cin >> n >> m >> x >> y;
	vector<int> row(n);
	for (int i = 0; i < n; i++) cin >> row[i];
	vector<int> col(m);
	for (int i = 0; i < m; i++) cin >> col[i];
	cout << n+m << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}