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
int Xor[MAXN*4], x[MAXN];
void Build(int id, int l, int r) {
	if (l == r) {
		Xor[id] = x[l];
		return;
	}
	int m = (l+r)/2;
	Build(id*2,l,m);
	Build(id*2+1,m+1,r);
	Xor[id] = Xor[id*2] ^ Xor[id*2+1];
}
int Get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return Xor[id];
	int m = (l+r)/2;
	int Xor1 = Get(id*2,l,m,u,v);
	int Xor2 = Get(id*2+1,m+1,r,u,v);
	return Xor1 ^ Xor2;
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> x[i];
	Build(1,1,n);
	while (q--) {
		int a, b; cin >> a >> b;
		cout << Get(1,1,n,a,b) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
