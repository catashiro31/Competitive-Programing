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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) cnt++;
		}
		if (cnt == 0) {
			cout << 1 << endl;
			cout << 1 << " " << n << endl;
		} else if (cnt == n) {
			cout << 3 << endl;
			cout << 1 << " " << 2 << endl;
			cout << 2 << " " << n-1 << endl;
			cout << 1 << " " << 2 << endl;
		} else {
			vector<pair<int,int>> kq;
			if (a[0] == 0 && a[n-1] == 0) {
				int i = 1;
				while (a[i] == 0) i++;
				cout << 3 << endl;
				if (i == 1) {
					kq.psb({1,2});
					kq.psb({2,n-1});
					kq.psb({1,2});
				} else if (i == n-2) {
					kq.psb({1,n-2});
					kq.psb({2,3});
					kq.psb({1,2});
				} else {
					kq.psb({1,i});
					kq.psb({3,n-(i-1)});
					kq.psb({1,3});
				}
			} else if (a[0] == 0) {
				cout << 2 << endl;
				kq.psb({1,n-1});
				kq.psb({1,2});
			} else if (a[n-1] == 0) {
				cout << 2 << endl;
				kq.psb({2,n});
				kq.psb({1,2});
			} else {
				cout << 2 << endl;
				kq.psb({2,n-1});
				kq.psb({1,3});
			}
			for (auto x : kq) cout << x.fi << " " << x.se << endl;
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
