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
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
void DFS(int u, vector<int> adjList[], vector<int> &kq) {
	for (int v : adjList[u]) {
		DFS(v,adjList,kq);
		kq[u] += kq[v];
	}
	kq[u]++;
}
void solve() {
	int n; cin >> n;
	vector<int> adjList[n];
	for (int node = 1; node < n; node++) {
		int parent; cin >> parent;
		--parent;
		adjList[parent].psb(node);
	}
	vector<int> kq(n,0);
	DFS(0,adjList,kq);
	for (int x : kq) cout << x-1 << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
