#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int m, n; cin >> m >> n;
	vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
	for (int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			if (i == j) dp[i][j] = 1;
			else {
				for (int k = 1; k < j; k++) {
					dp[i][j] = min(dp[i][j],dp[i][j-k] + dp[i][k]);
				}
				for (int k = 1; k < i; k++) {
					dp[i][j] = min(dp[i][j],dp[i-k][j] + dp[k][j]);
				}
			}
		}
	}
	cout << dp[m][n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
