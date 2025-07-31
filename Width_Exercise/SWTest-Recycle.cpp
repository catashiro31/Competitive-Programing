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
	int t; cin >> t;
	for (int q = 1; q <= t; q++) {
		int n; cin >> n;
		vector<pair<int,int>> pos[3];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x; cin >> x;
				if (!x) continue;
				pos[x-1].psb({i,j});
			}
		}
		pair<int,int> f[3];
		for (int i = 0; i < 3; i++) {
			cin >> f[i].fr >> f[i].sc;
			f[i].fr--, f[i].sc--;
		}
		int Ax, Ay; cin >> Ax >> Ay;
		Ax--, Ay--;
		int kq = 0;
		for (int i = 0; i < 3; i++) {
			auto [fx,fy] = f[i];
			int tmp = 0;
			for (auto [x,y] : pos[i]) {
				int di = abs(fx-x) + abs(fy-y);
				int da = abs(Ax-x) + abs(Ay-y);
				tmp = max(tmp,di - da);
				kq += di;
			}
			kq -= tmp;
		}
		cout << "#" << q << " " << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
