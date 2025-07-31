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
	vector<int> sl(1000001,0);
	vector<vector<int>> prefix(1000001,vector<int>(8,0));
	for (int i = 2; i <= 1000000; i++) {
		if (sl[i]) {
			prefix[i][sl[i]]++;
			continue;
		}
		prefix[i][1]++;
		for (int j = 2*i; j <= 1000000; j += i) sl[j]++;
	}
	for (int k = 1; k <= 7; k++) {
		for (int j = 1; j <= 1000000; j++) prefix[j][k] = prefix[j][k] + prefix[j-1][k];
	}
	int q; cin >> q;
	while (q--) {
		int a, b, k; cin >> a >> b >> k;
		cout << prefix[b][k] - prefix[a-1][k] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
