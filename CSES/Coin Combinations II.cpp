#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	int c[n];
	for (int &x : c) cin >> x;
	sort(c,c+n);
	vector<int> dp(x+1,0);
	dp[0] = 1;
	for (int k : c) {
		for (int i = 1; i <= x; i++) {
			if (k <= i) dp[i] = (dp[i]+dp[i-k])%mod;
		}
	}
	cout << dp[x];
	return 0;
}
