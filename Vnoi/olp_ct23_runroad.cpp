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
	int n; cin >> n;
	long t; cin >> t;
	vector<long> h(n);
	for (long &x : h) cin >> x;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	
	vector<vector<pair<int,long>>> dp(n,vector<pair<int,long>>(n,{INT_MAX,LONG_MIN}));
	for (int i = 0; i < n; i++) {
		queue<int> q; q.push(i);
		dp[i][i] = {0,h[i]};
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : adjList[u]) {
				if (dp[i][v].fi != INT_MAX) continue;
				dp[i][v].fi = dp[i][u].fi + 1;
				dp[i][v].se = max(dp[i][u].se,h[v]);
				q.push(v);
			}
		}
	}
	
	ll kq = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				long hmax = max(max(dp[i][j].se,dp[j][k].se),dp[k][i].se);
				if (hmax != t) continue;
				kq += dp[i][j].fi + dp[j][k].fi + dp[k][i].fi;
				kq %= mod;
			}
		}
	}
	cout << kq;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) cout << dp[i][j].fi << " ";
//		cout << endl;
//	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
