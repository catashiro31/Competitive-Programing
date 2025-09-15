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
void dijkstra(int src, const vector<pair<int,pair<ll,ll>>> adjList[], vector<ll> &a, vector<ll> &b, vector<ll> &dist) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({dist[src],src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v,wc] : adjList[u]) {
            auto [w,c] = wc;
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u] + w; 
                a[v] = max(a[u], c);
                b[v] = min(b[u], c);
                pq.push({dist[v], v});
            } else if (dist[u]+w == dist[v]) {
                a[v] = max(a[v], max(a[u], c));
                b[v] = min(b[v], min(b[u], c));
            }
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,pair<ll,ll>>> adjList[n];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        ll w, c; cin >> w >> c;
        adjList[u].psb({v,{w,c}});
        adjList[v].psb({u,{w,c}});
    }
    vector<ll> cmax1(n, LLONG_MIN), cmin1(n, LLONG_MAX), dist1(n,LLONG_MAX);
    dijkstra(0, adjList, cmax1, cmin1, dist1);
    vector<ll> cmax2(n, LLONG_MIN), cmin2(n, LLONG_MAX), dist2(n,LLONG_MAX);
    dijkstra(n-1, adjList, cmax2, cmin2, dist2);
    ll kq = 0;
    for (int i = 1 ; i < n-1; i++) {
        if (dist1[i] == LLONG_MAX || dist2[i] == LLONG_MAX) continue;
        if (dist1[i] + dist2[i] == dist1[n-1]) {
            kq = max(kq, cmax1[i] - cmin2[i]);
            kq = max(kq, cmax2[i] - cmin1[i]);
        }
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