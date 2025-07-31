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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> nxt(n+2,vector<int>(k,n+1));
    vector<int> d(n+2,INT_MAX);
    d[n+1] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < k; j++) nxt[i][j] = nxt[i+1][j];
        if (i < n) nxt[i][s[i]-'a'] = i+1;
        for (int j = 0; j < k; j++) d[i] = min(d[i],d[nxt[i][j]]+1);
    }
    int q; cin >> q;
    while(q--) {
        string t; cin >> t;
        int p = 0, kq = INT_MAX;
        for (char c : t) p = nxt[p][c-'a'];
        cout << d[p] << endl;
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