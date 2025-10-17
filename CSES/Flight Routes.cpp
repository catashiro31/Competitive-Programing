#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	ll n, m, k; cin >> n >> m >> k;
	vector<vector<pair<ll,ll>>> adjList(n);
	for (ll i = 0; i < m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		--u , --v;
		adjList[u].psb({v,c});
	}
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	priority_queue<ll> best[n];
	best[0].push(0);
	pq.push({0,0});
	while (!pq.empty()) {
		auto [d,u] = pq.top(); pq.pop();
		if (d > best[u].top()) continue;
		for (auto [v,c] : adjList[u]) {
			if (best[v].size() < k) {
				best[v].push(d+c);
				pq.push({d+c,v});
			} else {
				if (d+c < best[v].top()) {
					best[v].pop();
					best[v].push(d+c);
					pq.push({d+c,v});
				}
			}
		}
	}
	vector<ll> kq;
	while(!best[n-1].empty()) kq.psb(best[n-1].top()), best[n-1].pop();
	reverse(all(kq));
	for (ll x : kq) cout << x << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
