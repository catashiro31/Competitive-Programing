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
    
void solve() {
    int n, c; cin >> n >> c;
    vector<int> adjList[n];
    for (int i = 0; i < c; i++) {
        int e, b1, b2; cin >> e >> b1 >> b2;
        --e, --b1, --b2;
        adjList[e].psb(b1);
        adjList[b1].psb(e);
        adjList[e].psb(b2);
        adjList[b2].psb(e);
    }
    vector<int> dp(n,INT_MAX);
    dp[0] = 1;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adjList[u]) {
            if (dp[v] > dp[u]+1) {
                dp[v] = dp[u]+1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << dp[i] << endl;
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