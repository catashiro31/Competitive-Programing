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
    map<int,int> sl;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sl[x]++;
    }
    map<int,int> c;
    for (auto [u,v] : sl) {
        if (c[u] == 0) {
            if (v >= 4) {
                cout << "YES" << endl;
                return;
            } else if (v >= 2) c[u+1] = 1;
            else c[u] = 0;
        } else {
            if (v >= 2) {
                cout << "YES" << endl;
                return;
            } else if (v == 1) c[u+1] = 1;
            else c[u+1] = 0;
        }
    }
    cout << "NO" << endl;
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