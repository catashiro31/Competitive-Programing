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
vector<int> par(MAXN);
int Find(int u) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}
void solve() {
    int n; cin >> n;
    priority_queue<pair<int,int>> pq;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int i = 0; i < n; i++) pq.push({b[i],a[i]});
    int kq = 0;
    for (int i = 0; i <= n; i++) par[i] = i;
    while(!pq.empty()) {
        auto [b,a] = pq.top(); pq.pop();
        if (a > n) a = n;
        if (Find(a) == 0) kq += b;
        else par[Find(a)] = Find(Find(a)-1);
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