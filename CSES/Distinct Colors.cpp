#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
vector<int> c(MAXN), st(MAXN), en(MAXN);
int timer = 1;

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	vector<int> compress;
	for (int i = 1; i <= n; i++) compress.psb(c[i]);
	sort(all(compress));
	compress.erase(unique(all(compress)),compress.end());
	auto rank = [&](int v) {
		return lower_bound(all(compress),v) - compress.begin();	
	};
	
	for (int i = 1; i <= n; i++) c[i] = rank(c[i]);
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].psb(b);
		adj[b].psb(a);
	}
	st.assign(n+1,0), en.assign(n+1,0);
	vector<int> flat(n+1);
	
	int timer = 1;
    function<void(int,int)> euler_tour = [&](int u, int p) {
        st[u] = timer;
        flat[timer] = c[u];
        ++timer;
        for (int v : adj[u]) if (v != p) euler_tour(v, u);
        en[u] = timer - 1;
    };
	euler_tour(1,0);
	
	vector<pair<pair<int,int>,int>> arr;
	for (int i = 1; i <= n; i++) arr.psb({{st[i], en[i]},i});
	
	int block = max(1LL, (int)sqrt(n));
	sort(all(arr), [&](const auto &a, const auto &b){
	    int ab = a.first.first / block, bb = b.first.first / block;
	    if (ab != bb) return ab < bb;
	    if (ab & 1) return a.first.second > b.first.second;
	    return a.second < b.second;
	});
	
	int l = 1, r = 0, cnt = 0;
	vector<int> sl(sz(compress),0);
	vector<int> kq(n+1);
	for (auto [uv, id] : arr) {
		auto [u,v] = uv;
		while (r < v) {
			r++;
			if (sl[flat[r]] == 0) cnt++;
			sl[flat[r]]++;
		}
		while (u < l) {
			l--;
			if (sl[flat[l]] == 0) cnt++;
			sl[flat[l]]++;
		}
		while (l < u) {
			sl[flat[l]]--;
			if (sl[flat[l]] == 0) cnt--;
			l++;
		}
		while (v < r) {
			sl[flat[r]]--;
			if (sl[flat[r]] == 0) cnt--;
			r--;
		}
		kq[id] = cnt;
	}
	for (int i = 1; i <= n; i++) cout << kq[i] << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
