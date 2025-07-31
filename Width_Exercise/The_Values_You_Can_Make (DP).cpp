#include <bits/stdc++.h>
#define endl '\n'
#define mod 10000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	bool dp[2][k+1][k+1];
	memset(dp,false,sizeof(dp));
	dp[0][0][0] = true;
	for (int i = 1; i <= n; i++) {
		int now = i%2;
		int last = 1 - now;
		int x; cin >> x;
		for (int j = 0; j <= k; j++) {
			for (int y = 0; y <= j; y++) {
				dp[now][j][y] = dp[last][j][y];
				if (j >= x) {
					dp[now][j][y] |= dp[last][j-x][y];
					if (y >= x) dp[now][j][y] |= dp[last][j-x][y-x];
				}
			}
		}
	}
	vector<int> res;
	for (int i = 0; i <= k; i++) {
		if (dp[n%2][k][i]) res.push_back(i);
	}
	cout << res.size() << endl;
	for (int vl : res) cout << vl << " ";
}
