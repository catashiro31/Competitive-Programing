#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "piggyback";
void solve() {
	int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	vector<long> B(n,-1), E(n,-1), P(n,-1);
	B[0] = 0, E[1] = 0, P[n-1] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adjList[u]) {
			if (B[v] == -1) {
				B[v] = B[u] + b;
				q.push(v);
			}
		}
	}
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adjList[u]) {
			if (E[v] == -1) {
				E[v] = E[u] + e;
				q.push(v);
			}
		}
	}
	q.push(n-1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adjList[u]) {
			if (P[v] == -1) {
				P[v] = P[u] + p;
				q.push(v);
			}
		}
	}
	long kq = LONG_MAX;
	for (int i = 0; i < n; i++) {
		kq = min(kq,B[i] + E[i] + P[i]);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
