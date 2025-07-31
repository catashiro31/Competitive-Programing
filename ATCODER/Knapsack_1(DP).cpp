#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, W; cin >> n >> W;
	vector<int> w(n);
	vector<long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	vector<long long> dp(W+1,-1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = W; j >= w[i]; j--) {
			if (dp[j-w[i]] == -1) continue;
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
