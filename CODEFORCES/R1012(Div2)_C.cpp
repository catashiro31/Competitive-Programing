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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	vector<pair<int,pair<int,int>>> cell;
	vector<pair<int,pair<int,int>>> key;
	for (int x = 0; x < 500; x++) {
		for (int y = 0; y < 500; y++) {
			key.psb({3*x+1+3*y+1,{3*x+1,3*y+1}});
			cell.psb({3*x+1+3*y+2,{3*x+1,3*y+2}});
			cell.psb({3*x+2+3*y+1,{3*x+2,3*y+1}});
			cell.psb({3*x+2+3*y+2+2,{3*x+2,3*y+2}});
		}
	}
	sort(all(key));
	sort(all(cell));
	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		int u = 0, v = 0;
		for (int i = 0; i < n; i++) {
			int t; cin >> t;
			if (t) {
				if (cell[u] < key[v]) {
					cout << cell[u].se.fi << " " << cell[u].se.se << endl;
					u++;
				} else {
					cout << key[v].se.fi << " " << key[v].se.se << endl;
					v++;
				}
			} else {
				cout << key[v].se.fi << " " << key[v].se.se << endl;
				v++;
			}
		}
	}
}
