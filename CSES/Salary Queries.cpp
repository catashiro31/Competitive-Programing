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
#define endl '\n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
const int MAXN = 2e5+1;

void solve() {
	int n, q; cin >> n >> q;
	OST<pair<int,int>> ost;
	vector<int> p(n);
	for (int i = 0; i < n; i++){
		cin >> p[i];
		ost.insert({p[i],i});
	}
	while (q--) {
		char t; cin >> t;
		if (t == '?') {
			int a, b; cin >> a >> b;
			cout << ost.order_of_key({b,INT_MAX}) - ost.order_of_key({a,INT_MIN}) << endl;
		} else {
			int k, x; cin >> k >> x;
			--k;
			auto it = ost.lb({p[k],k});
			ost.erase(it);
			p[k] = x;
			ost.insert({x,k});
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
