#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
vector<vector<ll>> dp(MAXN,vector<ll>(2,1));
void DFS(int u, vector<int> adjList[], int p) {
	for (int v : adjList[u]) {
		if (v == p) continue;
		DFS(v,adjList,u);
		dp[u][0] = (dp[u][0] * ((dp[v][0]+dp[v][1])%MOD))%MOD;
		dp[u][1] = (dp[u][1] * dp[v][0])%MOD;
	}
}
void solve() {
	int n; cin >> n;
	vector<int> adjList[n];
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	DFS(0,adjList,-1);
	cout << (dp[0][0] + dp[0][1])%MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
