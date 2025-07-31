#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	int dp[n+1][k+2][3];
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		int tmp;
		if (x == 'P') tmp = 0;
		else if (x == 'H') tmp = 1;
		else tmp = 2;
		for (int j = 0; j <= k; j++) {
			for (int h = 0; h < 3; h++) {
				if (h == tmp) dp[i][j][h]++;
				dp[i+1][j][h] = max(dp[i+1][j][h],dp[i][j][h]);
				dp[i+1][j+1][0] = max(dp[i+1][j+1][0],dp[i][j][h]);
				dp[i+1][j+1][1] = max(dp[i+1][j+1][1],dp[i][j][h]);
				dp[i+1][j+1][2] = max(dp[i+1][j+1][2],dp[i][j][h]);
			}
		}
	}
	int kq = 0;
	for (int i = 0; i < 3; i++) kq = max(kq,dp[n-1][k][i]);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	solve();
}
