#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string n, m; cin >> n >> m;
	int size_n = n.size();
	int size_m = m.size();
	vector<vector<int>> dp(size_m + 1, vector<int>(size_n + 1, 0));
	for (int i = 0; i <= size_m; i++) dp[i][0] = i;
	for (int j = 0; j <= size_n; j++) dp[0][j] = j;
	for (int i = 1; i <= size_m; i++) {
		for (int j = 1; j <= size_n; j++) {
			if (n[j - 1] == m[i - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min({dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1 });
		}
	}
	cout << dp[size_m][size_n] << endl;
}
