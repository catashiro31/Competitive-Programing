#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 100005
vector<vector<int>> adj(MAXN);
vector<int> st(MAXN), en(MAXN), lan(MAXN), flat(MAXN);
int timer = 1;

void euler_tour(int u, int par) {
	st[u] = timer++;
	flat[st[u]] = lan[u];
	for (int v : adj[u]) {
		if (v == par) continue;
		euler_tour(v,u);
	}
	en[u] = timer-1; 
}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	for (int u = 2; u <= n; u++) {
		int v; cin >> v;
		adj[u].psb(v), adj[v].psb(u);
	}
	for (int i = 1; i <= n; i++) cin >> lan[i];
	euler_tour(1,0);	
	int q; cin >> q;
	vector<pair<pair<int,int>,int>> query(q);
	for (int i = 0; i < q; i++) {
		int u; cin >> u;
		query[i].first.first = st[u];
		query[i].first.second = en[u];
		query[i].second = i;
	}
	int block = sqrt(q);
	sort(all(query),[&](auto &a, auto &b){
		int ba = a.first.first/block, bb = b.first.first/block;
		if (ba != bb) return ba < bb;
		return a.first.second < b.first.second;	
	});
	vector<int> cnt(m+1,0), kq(q);
	vector<int> used(m+1,false);
	int l = 1, r = 0, sl = 0;
	for (auto [uv,id] : query) {
		auto [u,v] = uv;
		while (r < v) {
			r++;
			if (!used[flat[r]]) sl++, used[flat[r]] = true;
			cnt[flat[r]]++;
			if (cnt[flat[r]] > k && used[flat[r]]) sl--, used[flat[r]] = false;
		}
		while (l > u) {
			l--;
			if (!used[flat[l]]) sl++, used[flat[l]] = true;
			cnt[flat[l]]++;
			if (cnt[flat[l]] > k && used[flat[l]]) sl--, used[flat[l]] = false;
		}
		while (r > v) {
			if (cnt[flat[r]] == k+1 && !used[flat[r]]) sl++, used[flat[r]] = true;
			cnt[flat[r]]--;
			if (cnt[flat[r]] < 1) sl--, used[flat[r]] = false;
			r--;
		}
		while (l < u) {
			if (cnt[flat[l]] == k+1 && !used[flat[l]]) sl++, used[flat[l]] = true;
			cnt[flat[l]]--;
			if (cnt[flat[l]] < 1) sl--, used[flat[l]] = false;
			l++;
		}
		kq[id] = sl;
	}
	for (int x : kq) cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
