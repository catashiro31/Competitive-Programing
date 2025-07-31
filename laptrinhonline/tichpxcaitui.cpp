#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> dp(m+1,0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = m; j >= x; j--) {
			dp[j] = max(dp[j],dp[j-x]);
		}
	}
	for (int i = m; i > 0; i--) {
		if (dp[i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
