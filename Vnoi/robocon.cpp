#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> grid(1005,vector<int>(1005,0));
	for (int i = 0; i < k ; i++) {
		int x, y; cin >> x >> y;
		grid[x][y] = 1;
	}
	vector<vector<bool>> robot1(1005,vector<bool>(1005,false)), robot2(1005,vector<bool>(1005,false));
	robot1[1][1] = true, robot2[1][n] = true;
	for (int i = 1; i <= 2*n; i++) {
		for (int j = min(i+1,n); j >= 1; j--) {
			for (int k = min(i+1,n); k >= 1; k--) {
				if (grid[j][k]) robot1[j][k] = false;
				else robot1[j][k] = (robot1[j-1][k-1] || robot1[j-1][k] || robot1[j][k-1]);
			}
		}
		for (int j = min(i+1,n); j >= 1; j--) {
			for (int k = max(1LL,n-i); k <= n; k++) {
				if (grid[j][k]) robot2[j][k] = false;
				else robot2[j][k] = (robot2[j][k+1] || robot2[j-1][k] || robot2[j-1][k+1]);
				if (robot2[j][k] && robot1[j][k]) {
					cout << i << endl;
					return;
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
