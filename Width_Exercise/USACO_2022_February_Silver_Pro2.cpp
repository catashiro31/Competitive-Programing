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
	ll xg, yg; cin >> xg >> yg;
	vector<pair<ll,ll>> control(n);
	for (auto &x : control) cin >> x.fi >> x.se;
	map<pair<ll,ll>,vector<int>> sl;
	int m = (n-1)/2;
	for (int mask = 0; mask < (1 << m+1); mask++) {
		pair<ll,ll> tmp = {0,0};
		int cnt = 0;
		for (int i = 0; i < m+1; i++) {
			if (mask & (1 << i)) {
				tmp = {tmp.fi + control[i].fi,tmp.se + control[i].se};
				cnt++;
			}
		}
		sl[tmp].psb(cnt);
	}
	vector<int> kq(n+1,0);
	for (int mask = 0; mask < (1 << n-m-1); mask++) {
		pair<ll,ll> tmp = {0,0};
		int cnt = 0;
		for (int i = 0; i < n-m-1; i++) {
			if (mask & (1 << i)) {
				tmp = {tmp.fi + control[m+1+i].fi, tmp.se + control[m+1+i].se};
				cnt++;
			}
		}
		for (int x : sl[{xg-tmp.fi,yg-tmp.se}]) kq[cnt+x]++;
	}
	for (int i = 1; i <= n; i++) cout << kq[i] << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
