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
	int n, s, e, u, d; cin >> n >> s >> e >> u >> d;
	queue<int> q;
	vector<int> timer(n+5,LLONG_MAX);
	timer[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		if (p + u <= n && timer[p+u] > timer[p] + 1) {
			timer[p+u] = timer[p] + 1;
			q.push(p+u);
		}
		if (p - d >= 0 && timer[p-d] > timer[p]+1) {
			timer[p-d] = timer[p]+1;
			q.push(p-d);
		}
	}
	if (timer[e] == LLONG_MAX) cout << "impossible" << endl;
	else cout << timer[e] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
