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

pair<int,int> DFS(int u, int par,const vector<vector<int>> &adjList,const vector<bool> &used, vector<int> &p) {
    pair<int,int> ans = {1,u};
    p[u] = par;
    for (int v : adjList[u]) {
        if (used[v] || v == par) continue;
        auto pii = DFS(v,u,adjList,used,p);
        ans = max(ans,{pii.fi+1,pii.se});
    }    
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
    }

    vector<bool> used(n,false);
     vector<int> p(n,-1);
    vector<array<int,3>> kq;
    while(true) {
        if (count(all(used),false) == 0) break;
        p.assign(n,-1);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            auto [d1,u] = DFS(i,-1,adjList,used,p);
            auto [d2,v] = DFS(u,-1,adjList,used,p);
            int nxt = v;
            used[nxt] = true;
            while (p[nxt] != -1) nxt = p[nxt], used[nxt] = true;
            kq.psb({d2,max(u,v)+1,min(u,v)+1});
        }
    }
    sort(kq.rbegin(),kq.rend());
    for (auto [d,u,v] : kq) cout << d << " " << u << " " << v << " ";
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
