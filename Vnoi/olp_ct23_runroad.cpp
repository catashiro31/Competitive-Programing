#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 11;
const string NoF = "Name_of_File";
int n, t;
vector<int> adjList[MAXN];
int h[MAXN];
bool visited[MAXN];
ll s[MAXN];
void dfs(int u, int par, int lim) {
	visited[u] = true;
	s[u] = 1;
	for (int v : adjList[u]) {
		if (visited[v] || h[v] > lim) continue;
		dfs(v,u,lim);
		s[u] += s[v];
	}
}
ll cal(int u, int par, int lim, ll NumNode) {
	ll res = s[u];
	res = (res * ((NumNode - s[u] + MOD) % MOD)) % MOD;
	res = (res * ((NumNode - 2LL + MOD) % MOD)) % MOD;
	for (int v : adjList[u]) {
		if (v != par && h[v] <= lim) {
			res = (res + cal(v,u,lim,NumNode)) % MOD;
		}
	}
	return res;
}
ll f(int lim) {
	for (int i = 0; i <= n; i++) visited[i] = false;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && h[i] <= lim) {
			dfs(i, -1, lim);
			res = (res + cal(i,-1,lim,s[i])) % MOD;
		}
	}
	return res;
}
void solve() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	ll kq = (f(t) - f(t-1) + MOD) % MOD;
	cout << kq << endl;
}
	
int main() {
#ifndef ONLINE_JUDGE
	// freopen((NoF + ".in").c_str(), "r", stdin);
	// freopen((NoF + ".out").c_str(), "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test = 1;
	while(test--) {
		solve();
	}
}