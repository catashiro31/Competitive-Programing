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
	int t; cin >> t;
	for (int k = 0; k < t; k++) {
		int n, m; cin >> n >> m;
		vector<string> grid(n);
		for (int i = 0; i < n; i++) cin >> grid[i];
		vector<vector<int>> dp(n,vector<int>(m,0));
		long kq = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '0') continue;
				dp[i][j] = 1;
				if (i-1 >= 0) dp[i][j] += dp[i-1][j];
				if (j-1 >= 0) dp[i][j] += dp[i][j-1];
				if (i-1 >= 0 && j-1 >= 0 && (dp[i-1][j] != 0 || dp[i][j-1] != 0)) dp[i][j] -= dp[i-1][j-1];
				kq += dp[i][j];
			}
		}
		cout << "#" << k+1 << " " << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
