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
const string NoF = "Name_of_File";

void solve() {
	int n; cin >> n;
	vector<int> bfs(n), dfs(n);
	for (int &x : bfs) cin >> x;
	for (int &x : dfs) cin >> x;
	if (n == 1) cout << 0;
	else {
		if (bfs[1] != dfs[1]) cout << -1;
		else {
			vector<pair<int,int>> kq;
			for (int i = 1; i < n; i++) kq.psb({bfs[0],bfs[i]});
			for (int i = 1; i < n-1; i++) kq.psb({dfs[i],dfs[i+1]});
			cout << sz(kq) << endl;
			for (auto [u,v] : kq) cout << u << " " << v << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
