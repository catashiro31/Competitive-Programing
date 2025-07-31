#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int MAXN = 2e5;
vector<ll> sum(MAXN*4+1), a(MAXN+1);
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
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return sum[id];
	int m = (l+r) >> 1;
	ll sum1 = get(id*2,l,m,u,v);
	ll sum2 = get(id*2+1,m+1,r,u,v);
	return sum1 + sum2;
}
void update(int id, int l, int r, int p, long val) {
	if (p < l || p > r) return;
	if (l == r) {
		sum[id] = val;
		a[p] = val;
		return;
	}
	int m = (l+r) >> 1;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	sum[id] = sum[id*2] + sum[id*2+1];
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while(q--) {
		int t; cin >> t;
		if (t-1) {
			int a, b; cin >> a >> b;
			cout << get(1,1,n,a,b) << endl;
		} else {
			int k; cin >> k;
			long u; cin >> u;
			update(1,1,n,k,u);
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
