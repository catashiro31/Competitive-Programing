#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<int> segtree(4*MAXN,0), lazy(4*MAXN,0);

void push(int id) {
	segtree[id*2] += lazy[id];
	segtree[id*2+1] += lazy[id];
	lazy[id*2] += lazy[id];
	lazy[id*2+1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (r < u || v < l) return;;
	if (u <= l && r <= v) {
		segtree[id] += val;
		lazy[id] += val;
		return;
	}
	int m = (l+r)>>1;
	push(id);
	update(id*2,l,m,u,v,val);
	update(id*2+1,m+1,r,u,v,val);
	segtree[id] = max(segtree[id*2], segtree[id*2+1]);
}

void solve() {
	int n; cin >> n;
	vector<pair<pair<int,int>,int>> lrw(n);
	for (int i = 0; i < n; i++) {
		cin >> lrw[i].fi.fi >> lrw[i].fi.se >> lrw[i].se;
	}
	vector<int> arr;
	for (int i = 0; i < n; i++) arr.psb(lrw[i].fi.fi), arr.psb(lrw[i].fi.se);
	sort(all(arr));
	arr.erase(unique(all(arr)),arr.end());
	auto rank = [&](int v) {
		return lower_bound(all(arr),v) - arr.begin() + 1;	
	};
	sort(all(lrw),[](auto &a, auto &b){
		return a.fi.fi < b.fi.fi;	
	});
	int kq = 0;
	for (int i = n-1; i >= 0; i--) {
		int rank_r = rank(lrw[i].fi.se);
		update(1,1,arr.size(),rank_r,arr.size(),lrw[i].se);
		kq = max(kq,segtree[1]);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("SSEQ.INP","r",stdin);
//	freopen("SSEQ.OUT","w",stdout);

	int t = 1;
	while(t--) solve();
}
