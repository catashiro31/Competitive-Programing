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
const string NoF = "Name_of_File";

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<ll> sl(m+1,0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sl[x]++;
	}
	vector<pair<int,ll>> tk;
	for (int i = 1; i <= m; i++) tk.psb({i,sl[i]});
	sort(tk.begin(),tk.end(),[](auto a, auto b) {
		return a.sc < b.sc;
	});
	
	ll sum = 0;
	vector<ll> res(m);
	for (int i = 0; i < m; i++) {
		res[i] = tk[i].sc*i - sum;
		sum += tk[i].sc;
	}
	
	vector<pair<int,ll>> query(q);
	for (int i = 0; i < q; i++) {
		ll x; cin >> x;
		x -= n+1;
		query[i] = {i,x};
	}
	sort(query.begin(),query.end(),[](auto a, auto b) {
		return a.sc < b.sc;
	});
	
	OST<int> ost;
	int j = 0;
	for (int i = 0; i < q; i++) {
		ll x = query[i].sc;
		while (j < m) {
			if (x < res[j]) break;
			ost.insert(tk[j].fr);
			j++;
		}
		x -= res[j-1];
		int tmp = x % j;
		query[i].sc = *ost.find_by_order(tmp);
	}
	
	sort(query.begin(),query.end());
	for (auto x : query) cout << x.sc << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
