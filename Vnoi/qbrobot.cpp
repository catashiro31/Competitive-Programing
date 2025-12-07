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

void solve() {
	int n; cin >> n;
	vector<int> power(n);
	for (int &x : power) cin >> x;
	vector<vector<pair<int,pair<int,int>>>> adj(n);
	int m; cin >> m;
	for (int i = 0; i < m; i ++) {
		int u, v, t, c; cin >> u >> v >> t >> c;
		--u, --v;
		adj[u].psb({v,{t,c}});
		adj[v].psb({u,{t,c}});
	}
	vector<int> time(n,LLONG_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqt;
	pqt.push({0,0});
	time[0] = 0;
	while (!pqt.empty()) {
		auto [d,u] = pqt.top(); pqt.pop();
		if (d > time[u]) continue;
		for (auto [v,tc] : adj[u]) {
			auto [t,c] = tc;
			if (time[u]+t > time[v]) continue;
			time[v] = time[u] + t;
			pqt.push({time[v],v});
		}
	}
	int best_time = time[n-1];
	int l = 1, r = 1e10;
	int kq = -1;
	while(l<=r) {
		int m = (l+r)>>1;
		bool check = true;
		priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
		pq.push({0,0});
		vector<int> dist(n,LLONG_MAX), enery(n,0);
		dist[0] = 0, enery[0] = m;
		while(!pq.empty()) {
			auto [d,u] = pq.top(); pq.pop();
			if (d > dist[u]) continue;
			for (auto [v,tc] : adj[u]) {
				auto [t,c] = tc;
				if (dist[u] + t > dist[v] || enery[u] - c < 0) continue;
				if (dist[u] + t < dist[v]) {
					dist[v] = dist[u] + t;
					if (!power[v]) enery[v] = enery[u] - c;
					else enery[v] = m;
					pq.push({dist[v],v});
				} else {
					if (!power[v]) enery[v] = max(enery[v],enery[u]-c);
					else enery[v] = max(enery[v],m);
				}
			}
		}
		if (dist[n-1] != best_time) check = false;
		if (check) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
