#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long W; cin >> W;
	vector<long> w(n);
	vector<int> v(n);
	int maxvl = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		maxvl += v[i];
	}
	vector<long long> dp(maxvl+1,LLONG_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = maxvl; j >= v[i]; j--) {
			if (dp[j-v[i]] == LLONG_MAX) continue;
			dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	int result = INT_MIN;
	for (int i = 0; i <= maxvl; i++) {
		if (dp[i] <= W) result = max(result,i);
	}
	cout << result;
}
