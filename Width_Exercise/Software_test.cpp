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
int kq = INT_MAX;
void Try(int i, int end, vector<vector<int>> link, vector<int> &bulbs, vector<bool> &c, int par) {
    if (i == end) {
        bool check = true;
        for (int j = 0; j < sz(bulbs); j++) {
            if (bulbs[j] == 0) check = false;
        }
        if (check) kq = min(kq,end);
        return;
    }
    for (int j = par+1; j < sz(link); j++) {
        if (c[j]) continue;
        c[j] = true;
        for (int k = 0; k < sz(link[j]); k++) bulbs[link[j][k]] = 1-bulbs[link[j][k]];
        Try(i+1,end,link,bulbs,c,j);
        c[j] = false;
        for (int k = 0; k < sz(link[j]); k++) bulbs[link[j][k]] = 1-bulbs[link[j][k]];
    }
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> bulbs(n);
    for (int i = 0; i < n; i++) cin >> bulbs[i];
    vector<vector<int>> link(m,vector<int>(k));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> link[i][j];
            --link[i][j];
        }
    }
    vector<bool> c(m,false);
    for (int i = 1; i <= m; i++) {
        Try(0,i,link,bulbs,c,-1);
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