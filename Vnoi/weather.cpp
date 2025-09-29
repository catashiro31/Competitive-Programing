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
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
int res = 0;
stack<int> st;
void dfs(int u, vector<int> &visited, const vector<int> adjList[], vector<int> &incycle) {
    visited[u] = 1;
    for (int v : adjList[u]) {
        if (visited[v] == 1) continue; {
            
        }
        dfs(v,visited,adjList);
    }
    visited[u] = 2;
}
void solve() {
    int n; cin >> n;
    int m; cin >> m;
    vector<int> adjList[n];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    int kq = 0;
    for (int i = 0; i < n; i++) {
        
    }
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}