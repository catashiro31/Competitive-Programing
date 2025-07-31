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
		vector<vector<int>> grid(n+1,vector<int>(m+1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cin >> grid[i][j];
		}
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		int kq = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (grid[i][j]) continue;
				dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
				kq = max(kq,dp[i][j]);
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
