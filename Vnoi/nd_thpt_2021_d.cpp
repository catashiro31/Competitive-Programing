#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n; cin >> n;
	vector<int> t(n);
	for (int &x : t) cin >> x;
	vector<int> p(n-1);
	for (int &x : p) cin >> x;
	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = min(dp[i], dp[i-1]+t[i-1]);
		if (i >= 2) dp[i] = min(dp[i], dp[i-2]+p[i-2]);
	}
	cout << dp[n];
}

int main() {
	freopen("WORK.INP", "r", stdin);
    freopen("WORK.OUT", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
