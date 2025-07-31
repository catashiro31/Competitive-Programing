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
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		string kq = "z";
		for (int i = a[0]-2; i >= 0; i--) kq += i+'a';
		if (kq == "z" && n != 1) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			if (i % 2 == 1) {
				if (a[i] >= 26) {
					kq = "-1";
					break;
				}
				for (int j = 1; j < a[i]; j++) kq += char(j+'a');
				if (i+1 < n) {
					if (a[i+1] >= 26) {
						kq = "-1";
						break;
					}
					kq += char(max(a[i],a[i+1]) + 'a');
				} else kq += char(a[i] + 'a');
			} else {
				if (a[i] >= 26) {
					kq = "-1";
					break;
				}
				char tmp = kq[sz(kq)-1];
				for (int j = 1; j <= a[i]; j++) kq += char(tmp-j);
			}
		}
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
