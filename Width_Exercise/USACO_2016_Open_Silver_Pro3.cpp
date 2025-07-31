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
const string NoF = "closing";

void solve() {
	int n, m; cin >> n >> m;
	vector<int> adjList[n];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		adjList[u].psb(v);
		adjList[v].psb(u);
	}
	vector<int> q(n);
	for (int &x : q) cin >> x;
	reverse(q.begin(),q.end());
	vector<bool> c(n,false);
	vector<ool
	vector<string> kq;
	for (int i = 0; i < n; i++) {
		int u = q[i] - 1;
		if (i == 0) {
			c[u] = true;
			kq.psb("YES");
		} else {
			for (int v : adjList[u]) {
				if (c[v] == true) {
					c[u] = true;
					break;
				}
			}
			if (c[u] == true) kq.psb("YES");
			else kq.psb("NO");
		}
	}
	reverse(kq.begin(),kq.end());
	for (string x : kq) cout << x << endl;
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
