#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int MAXN = 1e6;
vector<long> mini(MAXN*4+1), x(MAXN+1); 
void build(int id, int l, int r) {
	if (l == r) {
		mini[id] = x[l];
		return;
	} 
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	mini[id] = min(mini[id*2],mini[id*2+1]);
}
long get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return LONG_MAX;
	if (u <= l && r <= v) return mini[id];
	int m = (l+r)/2;
	long mini1 = get(id*2,l,m,u,v);
	long mini2 = get(id*2+1,m+1,r,u,v);
	return min(mini1,mini2);
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
		mini[id] = val;
		x[p] = val;
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	mini[id] = min(mini[id*2],mini[id*2+1]);
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> x[i];
	build(1,1,n);
	while(q--) {
		int t; cin >> t;
		if (t-1) {
			int u, v; cin >> u >> v;
			cout << get(1,1,n,u,v) << endl;
		} else {
			int p; cin >> p;
			long val; cin >> val;
			update(1,1,n,p,val);
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
