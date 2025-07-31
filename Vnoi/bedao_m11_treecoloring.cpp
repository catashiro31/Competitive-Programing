#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void DFS(int u, vector<pair<int,long>> adjList[], vector<int> &kq) {
	for (auto [v,w] : adjList[u]) {
		if (kq[v] == -1) {
			if (w % 2) kq[v] = 1 - kq[u];
			else kq[v] = kq[u];
			DFS(v,adjList,kq);
		}
	}
}
void solve() {
	int n; cin >> n;
	vector<pair<int,long>> adjList[n];
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		long w; cin >> w;
		adjList[u].pb({v,w});
		adjList[v].pb({u,w});
	}
	vector<int> kq(n,-1);
	kq[0] = 0;
	DFS(0,adjList,kq);
	for (int x : kq) cout << x << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
