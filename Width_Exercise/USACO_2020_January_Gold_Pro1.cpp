#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, m, c; cin >> n >> m >> c;
	vector<int> moonie(n);
	for (int &x : moonie) cin >> x;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].pb(v);
	} 
	const int MAX_DAYS = 1000;
	vector<vector<long>> dp(MAX_DAYS+1,vector<long>(n,-1));
	dp[0][0] = 0;
	long kq = -1;
	for (int i = 0; i < MAX_DAYS; i++) {
		for (int u = 0; u < n; u++) {
			if (dp[i][u] == -1) continue;
			for (int v : adjList[u]) {
				dp[i+1][v] = max(dp[i+1][v],dp[i][u] + moonie[v]);
			}
		}
		kq = max(kq,dp[i][0] - c*i*i);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	solve();
}
