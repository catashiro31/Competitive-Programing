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
const int MAXN = 1e5 + 1;
const string NoF = "Name_of_File";
int n;
vector<int> adjList[MAXN];
vector<ll> val(MAXN);
pair<ll, ll> DFS(int u, int par) {
	ll add = 0, sub = 0;
	for (int v : adjList[u]) {
		if (v == par) continue;
		auto [a,s] = DFS(v, u);
		add = max(add,a);
		sub = max(sub,s);
	}
	val[u] += add - sub;
	if (val[u] >= 0) sub += val[u];
	else add -= val[u];
	val[u] = 0;
	return {add, sub};
}
void solve() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	for (int i = 0; i < n; i++) cin >> val[i];
	auto [add, sub] = DFS(0, -1);
	cout << add + sub;
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