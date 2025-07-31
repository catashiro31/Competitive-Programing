#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
const long long m = 998244353;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int q, k; cin >> q >> k;
	vector<long long> dp(k+1,0);
	dp[0] = 1;
	while (q--) {
		char c; cin >> c;
		int x; cin >> x;
		if (c == '+') {
			for (int i = k; i >= x; i--) {
				dp[i] = (dp[i]+dp[i-x])%m;
			}
		} else {
			for (int i = x; i <= k; i++) {
				dp[i] = (dp[i]-dp[i-x]+m)%m;
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}