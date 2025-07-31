#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string x, y; cin >> x >> y;
	int n = x.size(), m = y.size();
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	set<string> kq[n+1][m+1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i-1] == y[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				if (dp[i][j] == 1) kq[i][j].insert(string(1,x[i-1]));
				else {
					for (string s : kq[i-1][j-1]) kq[i][j].insert(s+x[i-1]);
				}
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if (dp[i][j] == dp[i-1][j]) for (string s : kq[i-1][j]) kq[i][j].insert(s);
				if (dp[i][j] == dp[i][j-1]) for (string s : kq[i][j-1]) kq[i][j].insert(s);
			}
		}
	}
	for (string s : kq[n][m]) cout << s << endl;
}
