#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> dp(m+1,-1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j <= m-x; j++) {
			if (dp[j] == -1) continue;
			if (dp[j+x] == -1) dp[j+x] = dp[j]+1;
			else dp[j+x] = min(dp[j+x],dp[j]+1);
		}
	}
	if (dp[m] == -1) cout << "ATM khong the tra tien";
	else cout << dp[m];
}
