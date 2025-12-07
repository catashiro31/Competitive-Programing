#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 100005
int n;
vector<int> a(MAXN), sl(MAXN,0);
vector<vector<int>> adj(MAXN);
int kq = 0, cnt = 0;
void dfs(int u, int par) {
	if (sl[a[u]] == 0) sl[a[u]]++, cnt++;
	else sl[a[u]]++;
	kq += cnt;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v,u);
	}
	if (sl[a[u]] == 1) sl[a[u]]--, cnt--;
	else sl[a[u]]--;
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].psb(v);
		adj[v].psb(u);
	}
	for (int i = 0; i < n; i++) {
		kq = 0;
		dfs(i,-1);
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
