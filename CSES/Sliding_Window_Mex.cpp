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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> sl(k+1,0);
    set<int> s;
    for (int i = 0; i <= k; i++) s.insert(i);
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            if (sl[a[i]] == 0) s.erase(a[i]);
            sl[a[i]]++;
        }
        if (i >= k) {
            if (a[i-k] <= k) {
                if (sl[a[i-k]] == 1) s.insert(a[i-k]);
                sl[a[i-k]]--;
            }
        }
        if (i >= k-1) cout << *s.begin() << " ";
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