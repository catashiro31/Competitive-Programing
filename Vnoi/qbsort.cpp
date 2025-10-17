#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n, k; cin >> n >> k;
	vector<int> color(n);
	for (int &x : color) cin >> x;
	vector<vector<int>> cost(k+1, vector<int>(k+1));
	vector<int> sum(k+1,0);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == color[i]) continue;
			cost[j][color[i]] += sum[j];
		}
		sum[color[i]]++;
	} 
	vector<int> dp((1<<k), INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < (1<<k); i++) {
		for (int j = 0; j < k; j++) {
			if (i&(1<<j)) {
				int mask = i ^ (1<<j);
				int add = 0;
				for (int h = 0; h < k; h++) {
					if (mask&(1<<h)) {
						if (dp[mask] == INT_MAX) continue;
						add += cost[h+1][j+1];
					}
				}
				dp[i] = min(dp[i], dp[mask] + add);
			}
		}
	}
	cout << dp[(1<<k)-1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
