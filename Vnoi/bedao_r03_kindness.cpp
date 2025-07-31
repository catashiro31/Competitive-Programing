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
	string s; cin >> s;
	ll n = s.length();
	vector<ll> cnt(26,0);
	for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
	ll flag = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 2) flag = 1;
	}
	ll kq = n*(n-1)/2;;
	for (int i = 0; i < 26; i++) kq -= cnt[i]*(cnt[i]-1)/2;
	cout << kq + flag;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
