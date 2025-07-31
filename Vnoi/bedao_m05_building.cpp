#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int MAXN = 1e6;
ll S[MAXN], a[MAXN];
void build(int id, int l, int r) {
	if (l == r) {
		S[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	S[id] = S[id*2]+S[id*2+1];
}
ll get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return S[id];
	int m = (l+r)/2;
	ll s1 = get(id*2,l,m,u,v);
	ll s2 = get(id*2+1,m+1,r,u,v);
	return s1 + s2;
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || r < p) return;
	if (l == r) {
		S[id] = val;
		a[l] = val;
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	S[id] = S[id*2] + S[id*2+1];
}
void solve() {
	int n; cin >> n;
	vector<ll> h(n);
	for (ll &x : h) cin >> x;
	for (int i = 1; i < n; i++) a[i] = abs(h[i]-h[i-1]);
	build(1,1,n-1);
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t-1) {
			int u, v; cin >> u >> v;
			cout << get(1,1,n-1,u,v-1) << endl;
		} else {
			int p; cin >> p;
			ll x; cin >> x;
			h[--p] = x;
			if (p != 0) update(1,1,n-1,p,abs(h[p]-h[p-1]));
			if (p != n-1) update(1,1,n-1,p+1,abs(h[p+1]-h[p]));
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
