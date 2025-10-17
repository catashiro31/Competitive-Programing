#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> edge(n-1);
	for (int i = 0; i < n-1; i++) {
		cin >> edge[i].first >> edge[i].second;
		edge[i].first--, edge[i].second--;
	}
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	int cnt = 0;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < n-1; i++) {
		auto [u,v] = edge[i];
		adjList[u].psb(v);
		adjList[v].psb(u);
		if (c[u] != c[v]) cnt++;
	}
	vector<int> kq;
	for (int i = 0; i < n; i++) {
		int sl = 0;
		for (int v : adjList[i]) {
			if (c[i] != c[v]) sl++;
		}
		if (sl == cnt) kq.psb(i);
	}
	sort(all(kq));
	if (kq.size()) {
		cout << "YES" << endl;
		for (int x : kq) cout << x+1 << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
