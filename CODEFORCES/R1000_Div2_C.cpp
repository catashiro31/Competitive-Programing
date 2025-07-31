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
void solve() {
    int n; cin >> n;
    vector<vector<int>> adjList(n);
    vector<int> degree(n,0);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adjList[u].psb(v);
        adjList[v].psb(u);
        degree[u]++, degree[v]++;
    }
    int cmaxf = *max_element(all(degree));
    vector<int> max_degree, no_max;
    for (int i = 0; i < n; i++) {
        if (degree[i] == cmaxf) max_degree.psb(i);
        else no_max.psb(i);
    }
        int kq = 0;
    if (sz(max_degree) >= 2) {
        for (int u : no_max) {
            for (int v : adjList[u]) degree[u]--, degree[v]--;
        }
        int cmin = INT_MAX;
        for (int u : max_degree) cmin = min(cmin,degree[u]);
        if (cmin == sz(max_degree)-1) kq = cmaxf + cmaxf - 2;
        else kq = cmaxf + cmaxf - 1;
    } else {
        for (int v : adjList[max_degree[0]]) kq = max(kq,degree[v]+degree[max_degree[0]]-2), degree[v] = 0;
        degree[max_degree[0]] = 0;
        int cmaxs = *max_element(all(degree));
        kq = max(kq,cmaxf+cmaxs-1);
    }
    cout << kq << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}