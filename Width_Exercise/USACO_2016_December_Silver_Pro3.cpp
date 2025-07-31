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
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "moocast";
int check[200], sl;
void DFS(int u, vector<int> adjList[]) {
	check[u] = 1;
	for (int v : adjList[u]) {
		if (check[v] == 0) DFS(v,adjList);
	}
	sl++;
}
void solve() {
	int n; cin >> n;
	int x[n], y[n], p[n];
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> p[i];
	vector<int> adjList[n];
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if (u == v) continue;
			int d = pow(x[u]-x[v],2) + pow(y[u]-y[v],2);
			if (d <= p[u]*p[u]) adjList[u].psb(v);
		}
	}
	int kq = 0;
	for (int i = 0; i < n; i++) {
		memset(check,0,sizeof(check));
		sl = 0;
		DFS(i,adjList);
		kq = max(kq,sl);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
