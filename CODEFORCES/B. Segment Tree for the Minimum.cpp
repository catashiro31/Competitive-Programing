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
long minimum[maxn*4], a[maxn];
void build(int id, int l, int r) {
	if (l == r) {
		minimum[id] = a[l];
		return;
	}
	int m = (l+r) >> 1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	minimum[id] = min(minimum[id*2],minimum[id*2+1]);
}
long get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) return LONG_MAX;
	if (u <= l && r <= v) return minimum[id];
	int m = (l+r) >> 1;
	long min1 = get(id*2,l,m,u,v);
	long min2 = get(id*2+1,m+1,r,u,v);
	return min(min1,min2);
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
		minimum[id] = val;
		a[p] = val;
		return;
	}
	int m = (l+r) >> 1;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	minimum[id] = min(minimum[id*2],minimum[id*2+1]);
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
			long val; cin >> val;
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
