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
    vector<int> u(n);
    for (int &x : u) cin >> x;
    vector<int> d(n);
    for (int &x : d) cin >> x;
    set<int> st;
    int cmax = -1, cmin = INT_MAX;
    for (int i = 0; i < n; i++) {
        cmax = max(cmax,u[i]);
        cmin = min(cmin,u[i]);
        if (u[i] != -1 && d[i] != -1) st.insert(u[i]+d[i]);
    }
    if (sz(st) > 1) cout << 0 << endl;
    else if (sz(st) == 1) {
        if (cmax > *(st.begin()) || *(st.begin()) > cmin+k) cout << 0 << endl;
        else cout << 1 << endl;
    } else cout << max(0,cmin+k-cmax+1) << endl;
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