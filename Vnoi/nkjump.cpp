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
int kq = 0;
void DFS(int u, vector<bool> &visited, vector<int> adjList[], stack<int> &st) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (visited[v]) continue;
        DFS(v,visited,adjList,st);
    }
    st.push(u);
}
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<int> adjList[n];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i+1 < n; i++) {
            if (i == k) continue;
            for (int j = i+1; j < n; j++) {
                if (j == k) continue;
                if (a[i]+a[j] == a[k]) {
                    adjList[i].psb(k);
                    adjList[j].psb(k);
                }
            }
        }
    }
    stack<int> st;
    vector<bool> visited(n,false);
    for (int u = 0; u < n; u++) {
        if (visited[u]) continue;
        DFS(u,visited,adjList,st);
    }
    vector<int> toposort;
    while (!st.empty()) toposort.psb(st.top()), st.pop();
    vector<int> dp(n,1);
    int kq = 0;
    for (int u : toposort) {
        for (int v : adjList[u]) dp[v] = max(dp[v],dp[u]+1);
        kq = max(kq,dp[u]);
    }
    cout << kq;
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