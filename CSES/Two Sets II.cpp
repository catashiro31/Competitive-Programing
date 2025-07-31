#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = n*(n+1)/2;
	if (sum & 1) {
		cout << 0;
		return 0;
	}
	sum /= 2;
	vector<long> dp(sum+1,0);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = sum-i; j >= 0; j--) {
			dp[j+i] = (dp[j+i]+dp[j])%mod;
		}
	}
	cout << dp[sum];
	return 0;
}