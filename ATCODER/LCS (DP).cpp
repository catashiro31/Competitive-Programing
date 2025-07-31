#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s, t; cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	int i = n, j = m;
	string ans = "";
	while (i > 0 && j > 0) {
		if (s[i-1] == t[j-1]) {
			ans = s[i-1] + ans;
			i--; j--;
		} else if (dp[i][j-1] == dp[i][j]) j--;
		else i--;
	}
	cout << ans;
}
