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
    int m, n; cin >> m >> n;
    vector<pair<int,int>> ud(n);
    for (int i = 0; i < n; i++) {
        cin >> ud[i].fi;
        ud[i].se = m - ud[i].fi;
    }
    stack<int> st1, st2;
    vector<pair<int,int>> left(n), right(n);
    for (int i = 0; i < n; i++) {
        auto [u,d] = ud[i];
        while (!st1.empty() && ud[st1.top()].fi >= u) st1.pop();
        while (!st2.empty() && ud[st2.top()].se >= d) st2.pop();
        if (st1.empty()) left[i].fi = -1;
        else left[i].fi = st1.top();
        if (st2.empty()) left[i].se = -1;
        else left[i].se = st2.top();
        st1.push(i), st2.push(i); 
    }
    while (!st1.empty()) st1.pop();
    while (!st2.empty()) st2.pop();
    for (int i = n-1; i >= 0; i--) {
        auto [u,d] = ud[i];
        while (!st1.empty() && ud[st1.top()].fi >= u) st1.pop();
        while (!st2.empty() && ud[st2.top()].se >= d) st2.pop();
        if (st1.empty()) right[i].fi = n;
        else right[i].fi = st1.top();
        if (st2.empty()) right[i].se = n;
        else right[i].se = st2.top();
        st1.push(i), st2.push(i); 
    }
    ll kq = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        auto [u,d] = ud[i];
        kq = max(kq,1LL*(right[i].fi-left[i].fi-1)*u);
        kq = max(kq,1LL*(right[i].se-left[i].se-1)*d);
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