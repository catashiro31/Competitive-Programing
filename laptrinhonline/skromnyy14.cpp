#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
const int maxn = 2e6;
struct edge {
	int u, v;
	ll w;
};
int Find(int u) {
	if (r[u] == u) return u;
	return r[u] = Find(r[u]);
}
bool Union(int u, int v) {
	int ru = Find(u), rv = Find(v);
	if (ru == rv) return false;
	else {
		r[rv] = ru;
		return true;
	}
}
void solve() {
	int n, m; cin >> n >> m;
	vector<bool> c(n,false);
	vector<int> r(n);
	for (int i = 0; i < n; i++) r[i] = i;
	int s; cin >> s;
	c[s] = true;
	vector<edge> e;
	ll kq = LLONG_MAX;
	for (int i = 0; i < m; i++) {
		edge x; cin >> x.u >> x.v >> x.w;
		if (x.v == s) continue;
		if (x.u == s) kq = min(kq,x.w);
		else e.pb(x);
	}	
	sort(e.begin(),e.end(),[](edge a,edge b) {
		return a.w < b.w;
	});
	for (auto [u,v,w] : e) {
		int ru = Find(u), rv = Find(v);
		if  ()
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
