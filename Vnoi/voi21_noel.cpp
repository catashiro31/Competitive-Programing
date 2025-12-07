#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, d; cin >> n >> d;
	vector<int> c(2*n);
	for (int &x : c) cin >> x;
	int kq = 0;
	vector<vector<int>> dp(2005,vector<int>(2005));
	for (int i = 0; i < 2*n; i++) {
		int na = i+1, nb = 2*n - na; 
		for (int j = 0; j <= na; j++) {
			for (int k = 0; k <= nb; k++) dp[j][k] = 0;
		}
		for (int j = 1; j <= na; j++) {
			for (int k = 1; k <= nb; k++) {
				dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
				if (abs(c[j-1]-c[na+k-1]) <= d) {
					dp[j][k] = max(dp[j][k], dp[j-1][k-1]+1);
				}
			}
		}
		kq = max(kq,dp[na][nb]);
	}
	cout << min(kq,n) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	while(t--) solve();
}