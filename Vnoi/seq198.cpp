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
	int m; cin >> m;
	vector<int> b(m);
	for (int &x : b) cin >> x;
	vector<int> degree(m,0);
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			if (abs(b[i]-b[j]) == 1 || abs(b[i]-b[j]) == 8 || abs(b[i]-b[j]) == 9) {
				degree[i]++, degree[j]++;
			}
		}
	}
	
	int kq = 0;
	queue<int> q;
	int pos = -1;
	for (int i = 0; i < m; i++) {
		if (degree[i] >= 1) {
			if (pos == -1) pos = i;
			else pos = degree[pos] > degree[i] ? pos : i;
		}
	} 
	if (pos != -1) q.push(pos);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (!degree[u]) continue;
		kq++; degree[u] = 0;
		for (int i = 0; i < m; i++) {
			if (i == u) continue;
			if (abs(b[i]-b[u]) == 1 || abs(b[i]-b[u]) == 8 || abs(b[i]-b[u]) == 9) degree[i]--;
		}
		int p = -1;
		for (int i = 0; i < m; i++) {
			if (degree[i] >= 1) {
				if (p == -1) p = i;
				else p = degree[p] > degree[i] ? p : i;
			}
		} 
		if (p != -1) q.push(p);
	} 
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
