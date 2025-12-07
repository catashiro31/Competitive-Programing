#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (*max_element(a.begin()+1,a.end()) > m) {
		cout << -1;
		return;
	}
	vector<int> dp(n+1,LLONG_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int j = i, sum = 0, cmax = LLONG_MIN;
		while (j > 0 && sum + a[j] <= m) {
			sum += a[j], cmax = max(cmax,a[j]);
			dp[i] = min(dp[i], dp[j-1] + cmax);
			j--;
		}
	}
	cout << dp[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
