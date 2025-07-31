#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename TP>
using OST =
	tree<TP, null_type, less<TP>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '/n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
int root[MAXN];
int Find(int u) {
	if (root[u] == u) return u;
	return root[u] = Find(root[u]);
}
bool Union(int u, int v) {
	int ru = Find(u), rv = Find(v);
	if (ru == rv) return false;
	if (ru > rv) swap(ru,rv);
	root[rv] = ru;
	return true;
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) root[i] = i;
	vector<pair<pair<int,int>,int>> e;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		e.psb({{u,v},c});
	}
	sort(e.begin(),e.end(), [](auto a, auto b) {
		return a.sc < b.sc;	
	});
	ll kq = 0;
	for (auto [x,c] : e) {
		auto [u,v] = x;
		if (Union(u,v)) kq+=c;
	}
	for (int i = 1; i <= n; i++) {
		if (Find(i) != 1) {
			cout << "IMPOSSIBLE";
			return;
		}
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
