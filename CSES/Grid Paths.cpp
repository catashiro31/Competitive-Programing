#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<char>> Grid(n,vector<char> (n));
	for (int i = 0; i < n; i++) {
		string x; cin >> x;
		for (int j = 0; j < n; j++) {
			Grid[i][j] = x[j];
		}
	}
	vector<vector<long long>> dp(n+1,vector<long long> (n+1,0));
	if (Grid[0][0] != '*') dp[1][1] = 1;
	else {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (Grid[i-1][j-1] == '*') continue;
			dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	cout << dp[n][n];
}