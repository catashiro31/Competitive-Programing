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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
ll kq = 0;
pair<ll,ll> DFS(int u, int par, const vector<vector<int>> &adjList, vector<ll> &val) {
	ll ans = 0, tmp = 0;
	for (int v : adjList[u]) {
		if (v == par) continue;
		auto e = DFS(v,u,adjList,val);
		val[u] += e.fi+e.se;
		tmp += e.fi;
	}
	kq += abs(val[u]);
	ans = -val[u];
	return {ans,tmp};
}
void solve() {
	int n; cin >> n;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u  >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	vector<ll> val(n);
	for (ll &x : val) cin >> x;
	auto z = DFS(0,-1,adjList,val);
	cout << kq;
}

int main() {
#ifndef ONLINE_JUDGE
	// freopen((NoF + ".in").c_str(), "r", stdin);
	// freopen((NoF + ".out").c_str(), "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--) {
		solve();
	}
}