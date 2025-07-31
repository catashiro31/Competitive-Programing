#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int h,w; cin >> h >> w;
	vector<vector<char>> Grid(h,vector<char> (w));
	for (int i = 0; i < h; i++) {
		string x; cin >> x;
		for (int j = 0; j < w; j++) {
			Grid[i][j] = x[j];
		}
	}
	vector<vector<long long>> dp(h+1,vector<long long> (w+1,0));
	dp[1][1] = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == 1 && j == 1) continue;
			if (Grid[i-1][j-1] == '#') continue;
			dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	cout << dp[h][w];
}
