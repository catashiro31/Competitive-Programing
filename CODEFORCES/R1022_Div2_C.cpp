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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> lpar(n), rpar(n);
    lpar[0] = INT_MAX, rpar[n-1] = INT_MAX;
    for (int i = 1; i < n; i++) lpar[i] = i-1;
    for (int i = 0; i < n-1; i++) rpar[i] = i+1;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) arr[i] = {a[i],i};
    sort(all(arr),greater<>());
    vector<bool> c(n,false);
    int kq = 0;
    for (int i = 0; i < n; i++) {
        int u = arr[i].se;
        if (c[u]) continue;
        while (true) {
            if (lpar[u] == INT_MAX && rpar[u] == INT_MAX) break;
            else if (lpar[u] == INT_MAX) {
                if (a[rpar[u]] > a[u]) break;
                lpar[rpar[u]] = lpar[u]; 
                u = rpar[u];
                c[u] = true;
            } else if (rpar[u] == INT_MAX) {
                if (a[lpar[u]] > a[u]) break;
                rpar[lpar[u]] = rpar[u];
                u = lpar[u];
                c[u] = true;
            } else {
                if (a[lpar[u]] > a[u] && a[rpar[u]] > a[u]) break;
                else if (a[lpar[u]] > a[u]) {
                    lpar[rpar[u]] = lpar[u];
                    rpar[lpar[u]] = rpar[u];
                    u = rpar[u];
                    c[u] = true;
                } else if (a[rpar[u]] > a[u]) {
                    rpar[lpar[u]] = rpar[u];
                    lpar[rpar[u]] = lpar[u];
                    u = lpar[u];
                    c[u] = true;
                } else {
                    if (a[lpar[u]] >= a[rpar[u]]) {
                        rpar[lpar[u]] = rpar[u];
                        lpar[rpar[u]] = lpar[u];
                        u = lpar[u];
                        c[u] = true;
                    } else {
                        lpar[rpar[u]] = lpar[u];
                        rpar[lpar[u]] = rpar[u];
                        u = rpar[u];
                        c[u] = true;
                    }
                }
            }
        }
        kq++;
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