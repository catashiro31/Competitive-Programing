#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	double p[n];
	for (double &x : p) cin >> x;
	vector<vector<double>> dp(n+1,vector<double> (n+1,0));
	dp[0][0] = 1.0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][0]*(1.0-p[i-1]);
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1.0-p[i-1]);
		}
	}
	double ans = 0;
	for (int i = n/2+1; i <= n; i++) ans += dp[n][i];
	cout << fixed << setprecision(10) << ans;
}