#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<long>> arr(3,vector<long> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> arr[j][i];
	}
	vector<vector<long>> dp(3,vector<long> (n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[j][i] = arr[j][i];
			if (i == 0) continue;
			for (int k = 0; k < 3; k++) {
				if (k == j) continue;
				dp[j][i] = max (dp[j][i],dp[k][i-1]+arr[j][i]);
			}
		}
	}
	long kq = LONG_MIN;
	for (int i = 0; i < 3; i++) {
		kq = max(kq,dp[i][n-1]);
	}
	cout << kq;
}
