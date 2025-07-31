#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";

void solve() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m, s; cin >> n >> m >> s;
		--s;
		vector<pair<int,int>> adjList[n], TadjList[n];
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
			--u, --v;
			adjList[u].psb({v,w});
			TadjList[v].psb({u,w});
		}
		vector<int> Go(n,INT_MAX);
		priority_queue<pair<int,int>> pq;
		pq.push({0,s});
		while(!pq.empty()) {
			auto [d,u] = pq.top(); pq.pop();
			if (d > Go[u]) continue;
			Go[u] = d;
			for (auto [v,w] : adjList[u]) {
				if (Go[u] + w < Go[v]) pq.push({Go[u]+w,v});
			}
		}
		vector<int> Back(n,INT_MAX);
		pq.push({0,s});
		while(!pq.empty()) {
			auto [d,u] = pq.top(); pq.pop();
			if (d > Back[u]) continue;
			Back[u] = d;
			for (auto [v,w] : TadjList[u]) {
				if (Back[u] + w < Back[v]) pq.push({Back[u]+w,v}); 
			}
		}
		int kq = -1;
		for (int i = 0; i < n; i++) {
			if (Go[i] != INT_MAX && Back[i] != INT_MAX) kq = max(kq,Go[i] + Back[i]);
			else kq = INT_MAX;
		}
		cout << "#" << i << " " << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
