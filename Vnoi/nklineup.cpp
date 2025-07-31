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
    int sparse_table[2][int(log2(n))+1][n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sparse_table[0][0][i] = x;
        sparse_table[1][0][i] = x;
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 0; j <= n-(1<<i); j++) {
            int p = j+(1<<i)-(1<<(i-1));
            sparse_table[0][i][j] = min(sparse_table[0][i-1][j],sparse_table[0][i-1][p]);
            sparse_table[1][i][j] = max(sparse_table[1][i-1][j],sparse_table[1][i-1][p]);
        }
    }
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        int d = log2(r-l+1), p = r-(1<<d)+1;
        cout << max(sparse_table[1][d][l],sparse_table[1][d][p]) - min(sparse_table[0][d][l],sparse_table[0][d][p]) << endl;
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