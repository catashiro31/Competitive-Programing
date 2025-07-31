#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<long> dp(n+1,0); dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = max(0,i-6); j < i; j++) {
			dp[i] = (dp[i]+dp[j])%mod;
		}
	}
	cout << dp[n];
	return 0;
}
