#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int maxn = 1e6;
ll sum[maxn*4], a[maxn];
void build(int id, int l, int r) {
	if (l == r) {
		sum[id] = a[l];
		return;
	}
	int m = (l+r) >> 1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	sum[id] = sum[id*2] + sum[id*2+1];
}
ll get(int id, int l, int r, int u, int v) {
	if (u > r || l > v) return 0;
	if (u <= l && v >= r) return sum[id];
	int m = (l+r) >> 1;
	ll sum1 = get(id*2,l,m,u,v);
	ll sum2 = get(id*2+1,m+1,r,u,v);
	return sum1 + sum2;
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
		sum[id] = val;
		a[l] = val;
		return;
	}
	int m = (l+r) >> 1;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	sum[id] = sum[id*2] + sum[id*2+1];
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (m--) {
		int t; cin >> t;
		if (t-1) {
			int u, v; cin >> u >> v;
			cout << get(1,1,n,u+1,v) << endl;
		} else {
			int p; cin >> p;
			ll val; cin >> val;
			update(1,1,n,p+1,val);
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
