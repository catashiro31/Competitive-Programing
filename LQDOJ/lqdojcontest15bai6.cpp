#include<bits/stdc++.h>

using namespace std;


void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int,pair<int,int>>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.psb({c,{u,v}});
	}
	sort(all(edges));
	vector<int> dp(n+1,0);
	for (int i = 0; i < m; i++) {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}