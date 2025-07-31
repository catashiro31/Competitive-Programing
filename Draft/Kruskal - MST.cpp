#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int r[10002];
struct edge {
	int u, v, w;
};
int Find(int u) {
	if (r[u] == u) return u;
	return r[u] = Find(r[u]);
}
bool Union(int u, int v) {
	int ru = Find(u), rv = Find(v);
	if (ru == rv) return false;
	r[rv] = ru;
	return true;
}
void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) r[i] = i;
	vector<edge> e(m);
	for (int i = 0; i < m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e.begin(),e.end(),[](edge a, edge b) {
		return a.w < b.w;		
	});
	int kq = 0;
	for (edge x : e) {
		if (Union(x.u,x.v)) kq += x.w;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}