#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int MAXN = 2e5;
ll s[10][MAXN*4+1], a[MAXN+1];
bool check(int i, int k) {
	if (i % k == 0) return true;
	while (i) {
		if (i % 10 == k) return true;
		i /= 10;
	}
	return false;
}
void build(int id, int l, int r, int k) {
	if (l == r) {
		if (check(l,k)) s[k][id] = a[l]*2;
		else s[k][id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m,k);
	build(id*2+1,m+1,r,k);
	s[k][id] = s[k][id*2] + s[k][id*2+1];
}
ll get(int id, int l, int r, int u, int v, int k) {
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return s[k][id];
	int m = (l+r)/2;
	ll s1 = get(id*2,l,m,u,v,k);
	ll s2 = get(id*2+1,m+1,r,u,v,k);
	return s1+s2;
}
void update(int id, int l, int r, int p, int k) {
	if (p < l || r < p) return;
	if (l == r) {
		if (check(l,k)) s[k][id] = a[l]*2;
		else s[k][id] = a[l];
		return;
	}
	int m = (l+r)/2;
	update(id*2,l,m,p,k);
	update(id*2+1,m+1,r,p,k);
	s[k][id] = s[k][id*2] + s[k][id*2+1];
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int k = 1; k <= 9; k++) build(1,1,n,k);
	while (q--) {
		int t; cin >> t;
		if (t-1) {
			int L, R, k; cin >> L >> R >> k;
			cout << get(1,1,n,L,R,k) << endl;
		} else {
			int i; cin >> i;
			ll c; cin >> c;
			a[i] = c;
			for (int k = 1; k <= 9; k++) update(1,1,n,i,k);
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
