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
	int k; cin >> k;
	string s; cin >> s;
	int n = s.length();
	map<char,int> sl;
	int i = 0, j = 0;
	int kq = INT_MAX;
	while (i < n) {
		sl[s[i]]++;
		if (sl['A'] < k || sl['V'] < k || sl['C'] < k) i++;
		else {
			while(j < i && sl[s[j]] > k) sl[s[j]]--, j++;
			kq = min(kq,sl['A'] + sl['V'] + sl['C'] - k*3);
			i++;
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
