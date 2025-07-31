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
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "fenceplan";
int minx = 0, maxx = 0, miny = 0, maxy = 0;
void DFS(int u, vector<int> adjList[], int x[], int y[], vector<int> &c) {
	c[u] = 1;
	for (int v : adjList[u]) {
		if (c[v] == 0) DFS(v,adjList,x,y,c);
	}
	minx = min(minx,x[u]);
	maxx = max(maxx,x[u]);
	miny = min(miny,y[u]);
	maxy = max(maxy,y[u]);
}
void solve() {
	int n, m; cin >> n >> m;
	int x[n], y[n];
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector<int> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	int kq = INT_MAX;
	vector<int> c(n,0);
	for (int i = 0; i < n; i++) {
		if (c[i] != 0) continue;
		minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
		DFS(i,adjList,x,y,c);
		kq = min(kq,(maxx-minx+maxy-miny)*2);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
