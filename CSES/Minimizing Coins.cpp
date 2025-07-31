#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	vector<int> c(n);
	for (int &k : c) cin >> k;
	sort(c.begin(),c.end());
	vector<long> dp(x+1,INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (int k : c) {
			if (k > i) break;
			else {
				dp[i] = min(dp[i],dp[i-k]+1);
			}
		}
	}
	if (dp[x] == INT_MAX) cout << -1;
	else cout << dp[x];
	return 0;
}
