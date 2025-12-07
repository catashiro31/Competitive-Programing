#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> b(n);
	for (int &x : b) cin >> x;
	vector<int> dp(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = b[i];
		sum += b[i];
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + b[i]);
		}
	}
	cout << sum - *max_element(all(dp)) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}