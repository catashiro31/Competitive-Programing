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
long mini[maxn*4], a[maxn];
int sl[maxn*4];
void build(int id, int l, int r) {
	if (l == r) {
		mini[id] = a[l], sl[id] = 1;
		return;
	}
	int m = (l+r) >> 1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	mini[id] = min(mini[id*2],mini[id*2+1]), sl[id] = 0;
	if (mini[id] == mini[id*2]) sl[id] += sl[id*2];
	if (mini[id] == mini[id*2+1]) sl[id] += sl[id*2+1]; 
}
pair<long,int> get(int id, int l, int r, int u, int v) {
	if (u > r || v < l) return {LONG_MAX,0};
	if (u <= l && r <= v) return {mini[id],sl[id]};
	int m = (l+r) >> 1;
	pair<long,int> get1 = get(id*2,l,m,u,v);
	pair<long,int> get2 = get(id*2+1,m+1,r,u,v);
	pair<long,int> ans;
	ans.fi = min(get1.fi,get2.fi), ans.se = 0;
	if (ans.fi == get1.fi) ans.se += get1.se;
	if (ans.fi == get2.fi) ans.se += get2.se;
	return ans;
}
void update(int id, int l, int r, int p, int val) {
	if (p < l || p > r) return;
	if (l == r) {
		mini[id] = val, sl[id] = 1;
		a[l] = val;
		return;
	}
	int m = (l+r) >> 1;
	update(id*2,l,m,p,val);
	update(id*2+1,m+1,r,p,val);
	mini[id] = min(mini[id*2],mini[id*2+1]), sl[id] = 0;
	if (mini[id] == mini[id*2]) sl[id] += sl[id*2];
	if (mini[id] == mini[id*2+1]) sl[id] += sl[id*2+1];
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while (m--) {
		int t; cin >> t;
		if (t-1) {
			int u, v; cin >> u >> v;
			pair<long,int> kq = get(1,1,n,u+1,v);
			cout << kq.fi << " " << kq.se << endl;
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
