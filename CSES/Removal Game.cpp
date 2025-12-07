#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 5005
int a[MAXN], dp[MAXN][MAXN];
int prefix[MAXN];
int cal(int l, int r) {
	if (dp[l][r] != LLONG_MIN) return dp[l][r];
	int sum = prefix[r] - prefix[l-1];
	dp[l][r] = max(sum-cal(l+1,r), sum-cal(l,r-1));
	return dp[l][r];
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = LLONG_MIN;
	}
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	for (int i = 1; i <= n; i++) dp[i][i] = a[i];
	cout << cal(1,n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
