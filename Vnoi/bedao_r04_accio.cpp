#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
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
	string s, t; cin >> s >> t;
	if (s.length() != t.length()) cout << -1;
	else {
		int n = s.length();
		char k = s[0];
		vector<int> p1, p2;
		for (int i = 0; i < n; i++) {
			if (s[i] == k) p1.psb(i);
			if (t[i] == k) p2.psb(i);
		}
		if (sz(p1) != sz(p2) || sz(p1) == n || sz(p2) == n) cout << -1;
		else {
			ll kq = 0;
			for (int i = 0; i < sz(p1); i++) kq += abs(p1[i]-p2[i]);
			cout << kq;
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
