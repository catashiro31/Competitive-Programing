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
int cur = 0, p = -1;
void dfs(int u, int par, const vector<int> adjList[], int d) {
    if (d > cur) {
        cur = max(d,cur);
        p = u;
    }
    for (int v : adjList[u]) {
        if (v == par) continue;
        dfs(v,u,adjList,d+1);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> adjList[n];
    vector<int> outgree(n,0);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }
    if (n == 1) cout << 0 << endl;
    else {
        dfs(0,-1,adjList,0);
        dfs(p,-1,adjList,0);
        cout << cur*3;
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