#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int maxn = 2e5+1;
vector<long> a(maxn*4);
void Push(int id) {
	a[id*2] += a[id];
	a[id*2+1] += a[id];
	a[id] = 0;
	return;
}
void Update(int id, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		a[id] += val;
		return;
	} 
	int m = (l+r)/2;
	Push(id);
	Update(id*2,l,m,u,v,val);
	Update(id*2+1,m+1,r,u,v,val);
}
long Get(int id, int l, int r, int p) {
	if (p < l || p > r) return 0;
	if (l == r) return a[id];
	int m = (l+r)/2;
	Push(id);
	long s1 = Get(id*2,l,m,p);
	long s2 = Get(id*2+1,m+1,r,p);
	return s1+s2;
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		long x; cin >> x;
		Update(1,1,n,i,i,x);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; cin >> a >> b;
			long u; cin >> u;
			Update(1,1,n,a,b,u);
		} else {
			int k; cin >> k;
			cout << Get(1,1,n,k) << endl;
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
