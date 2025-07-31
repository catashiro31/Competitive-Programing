#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
	
void solve() {
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	for (int &x : arr) cin >> x;
	vector<pair<int,int>> query(q);
	for (int i = 0; i < q; i++) {cin >> query[i].fi; query[i].se = i;}
	sort(all(query),greater<>());
	vector<int> kq(q);
	int i = 0, j = 0;
	while (j < q || i < n) {
		if (arr[i] <= query[j].fi) {kq[query[j].se] = i+1; j++;}
		else i++;
		if (j == q) break;
		if (i == n) {
			while (j < q) {kq[query[j].se] = 0; j++;}
		}
	}
	for (int x : kq) cout << x << endl;
}
	
int main() {
#ifndef ONLINE_JUDGE
	// freopen((NoF + ".in").c_str(), "r", stdin);
	// freopen((NoF + ".out").c_str(), "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--) {
		solve();
	}
}