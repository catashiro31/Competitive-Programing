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
void dfs(int u, int par, int val, const vector<vector<int>> &adjList, vector<int> &vis) {
    vis[u] = val;
    for (int v : adjList[u]) {
        if (vis[v] || v == par) continue;
        dfs(v,u,val,adjList,vis);
    }
}
    
void solve() {
    int n, m; cin >> n >> m;
    vector<bool> c(1e6+5,false);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        --x;
        c[x] = true;
    }
    vector<vector<int>> adjList(n);
    int l = 0, r = n-1;
    int cntl = 0, cntr = 0;
    while (l <= r) {
        if (cntl > 0) {
            adjList[r+1].psb(l);
            adjList[l].psb(r+1);
        }
        if (cntr > 0) {
            adjList[l-1].psb(r);
            adjList[r].psb(l-1);
        }
        if (c[l]) cntl++;
        if (c[r]) cntr++;
        if (cntl+cntr < m) {
            adjList[l].psb(r);
            adjList[r].psb(l);
        }
        l++, r--;
    }
    vector<int> vis(n,0);
    int j = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i,-1,j,adjList,vis);
        j++;
    }
    for (int x : vis) cout << x << " ";
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