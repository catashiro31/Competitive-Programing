#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define psb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
void DFS(int u, int par, const vector<vector<pair<int,int>>> &adjList, vector<int> &cal) {
    for (auto [v,l] : adjList[u]) {
        if (v == par) continue;
        cal[v] = cal[u] + l;
        DFS(v,u,adjList,cal);
    }
}
void solve() {
    int n, q; cin >> n >> q;
    vector<vector<pair<int,int>>> adjList(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, l; cin >> u >> v >> l;
        --u, --v;
        adjList[u].psb({v,l});
        adjList[v].psb({u,l});
    }
    vector<vector<int>> cal(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        cal[i][i] = 0;
        DFS(i,-1,adjList,cal[i]);
    }
    while (q--) {
        int u, v; cin >> u >> v;
        --u, --v;
        cout << cal[u][v] << endl;
    }
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}