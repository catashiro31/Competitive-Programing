#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	vector<vector<long long>> dp(n,vector<long long> (n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (i == 0) dp[j][j+i] = a[j+i];
			else {
				dp[j][j+i] = max(a[j]-dp[j+1][j+i],a[j+i]-dp[j][j+i-1]);
			}
		}
	}
	cout << dp[0][n-1];
}
