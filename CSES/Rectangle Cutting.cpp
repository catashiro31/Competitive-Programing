#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int a, b; cin >> a >> b;
	vector<vector<int>> dp(a,vector<int>(b,INT_MAX));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i == j) dp[i][j] = 0;
			else {
				for (int k = 1; k <= i; k++) dp[i][j] = min(dp[i][j],dp[k-1][j] + dp[i-k][j] + 1);
				for (int k = 1; k <= j; k++) dp[i][j] = min(dp[i][j],dp[i][k-1] + dp[i][j-k] + 1); 
			}
		}
	}
	cout << dp[a-1][b-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}