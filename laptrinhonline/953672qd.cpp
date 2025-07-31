#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 1e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
vector<int> adjList[MAXN];
vector<vector<int>> tk(10,vector<int>(MAXN,0));
int colour[MAXN];
void DFS(int u, int c, int p) {
	if (colour[u] == c) tk[c][u] = 1;
	for (int v : adjList[u]) {
		if (v == p) continue;
		DFS(v,c,u);
		tk[c][u] += tk[c][v];
	}
	return;
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	for (int i = 0; i < n; i++) cin >> colour[i];
	
	for (int c = 1; c <= 9; c++) DFS(0,c,-1);
	while (q--) {
		int u, c; cin >> u >> c;
		cout << tk[c][--u] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
