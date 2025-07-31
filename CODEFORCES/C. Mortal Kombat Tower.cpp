#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int kq = 0;
		vector<vector<ll>> dp(2,vector<ll>(n+1,INT_MAX));
		dp[1][0] = 0; 
		for (int i = 0; i < n; i++) {
			dp[0][i+1] = min(dp[0][i+1],dp[1][i] + a[i]);
			dp[1][i+1] = min(dp[1][i+1],dp[0][i]);
			if (i+2 <= n) {
				dp[0][i+2] = min(dp[0][i+2],dp[1][i] + a[i] + a[i+1]);
				dp[1][i+2] = min(dp[1][i+2],dp[0][i]);
			}
		}
		cout << min(dp[0][n],dp[1][n]) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
