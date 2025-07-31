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
const string NoF = "circlecross";

void solve() {
	int n; cin >> n;
	map<int,int> pos;
	OST<int> ost;
	int kq = 0;
	for (int i = 1; i <= 2*n; i++) {
		int x; cin >> x;
		if (pos[x] != 0) {
			ost.erase(pos[x]);
			kq += sz(ost) - ost.order_of_key(pos[x]);
		} else {
			ost.insert(i);
			pos[x] = i;
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
