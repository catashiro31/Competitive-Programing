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
    int n, q; cin >> n >> q;
    vector<int> a(n), p(n+2);
    for (int i = 0; i < n; i++) {cin >> a[i]; p[a[i]] = i;}
    p[0] = -1, p[n+1] = n;
    int sl = 1;
    for (int i = 1; i < n; i++) {
        if (p[i] < p[i+1]) continue;
        else sl++;
    }
    while (q--) {
        int u, v; cin >> u >> v;
        --u, --v;
        int tmp = 0;
        for (int i = a[u]-1; i < a[u]+1; i++) {
            if (p[i] < p[i+1]) continue;
            else tmp ++;
        }
        for (int i = a[v]-1; i < a[v]+1; i++) {
            if (i == a[u] || i+1 == a[u]) continue;
            if (p[i] < p[i+1]) continue;
            else tmp ++;
        }
        swap(a[u],a[v]);
        swap(p[a[u]],p[a[v]]);
        for (int i = a[u]-1; i < a[u]+1; i++) {
            if (p[i] < p[i+1]) continue;
            else tmp --;
        }
        for (int i = a[v]-1; i < a[v]+1; i++) {
            if (i == a[u] || i+1 == a[u]) continue;
            if (p[i] < p[i+1]) continue;
            else tmp --;
        }
        sl -= tmp;
        cout << sl << endl;
    }
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