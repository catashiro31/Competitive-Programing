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
    int n, m, k, src, dst; cin >> n >> m >> k >> src >> dst;
    --src, --dst;
    vector<vector<pair<int,ll>>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u ,--v;
        adjList[u].psb({v,w});
        adjList[v].psb({u,w});
    }
    vector<vector<ll>> dp(n,vector<ll>(k+1,LLONG_MAX));
    queue<pair<pair<int,int>,ll>> q;
    q.push({{src,0},0});
    while (!q.empty()) {
        auto [ut,p] = q.front(); q.pop();
        auto [u,t] = ut;
        if (dp[u][t] <= p) continue;
        dp[u][t] = p;
        for (auto [v,w] : adjList[u]) {
            if (dp[u][t] + w < dp[v][t]) {
                q.push({{v,t},dp[u][t]+w});
            }
            if (t < k && dp[u][t] < dp[v][t+1]) {
                q.push({{v,t+1},dp[u][t]});
            }
        }
    }
    cout << *min_element(all(dp[dst]));
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