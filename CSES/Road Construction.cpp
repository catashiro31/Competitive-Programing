#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int p[100001],sz[100001];
int sl = 1;
int Find(int u) {
	if (p[u] == u) return u;
	return p[u] = Find(p[u]);
}
bool Union(int u, int v) {
	int pu = Find(u), pv = Find(v);
	if (pu == pv) return false;
	else if (pu > pv) swap(pv,pu);
	p[pv] = pu;
	sz[pu] += sz[pv];
	sl = max(sl,sz[pu]);
	return true;
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
	int kq = n;
	while (m--) {
		int u, v; cin >> u >> v;
		--u, --v;
		if (Union(u,v)) --kq;
		cout << kq << " " << sl << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
