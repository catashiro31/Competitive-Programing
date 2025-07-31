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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));
    vector<bool> c(2e4+1,false);
    vector<vector<int>> pos(2e4+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (c[a[i]+a[j]] == false) {
                c[a[i]+a[j]] = true;
                pos[a[i]+a[j]].psb(i);
                pos[a[i]+a[j]].psb(j);
            } else {
                int p1 = pos[a[i]+a[j]][0], p2 = pos[a[i]+a[j]][1];
                pos[a[i]+a[j]].ppb();
                pos[a[i]+a[j]].ppb();
                if (p1 == i || p1 == j) pos[a[i]+a[j]].psb(p1);
                if (p2 == i || p2 == j) pos[a[i]+a[j]].psb(p2);
            }
        }
    }
    int kq = 0;
    for (int i = 0; i <= 2e4; i++) {
        if (!c[i]) continue;
        int tmp = m-i;
        int it = ub(all(a),tmp)-a.begin()-1;
        for (int j = sz(pos[i])-1; j >= 0; j--) {
            if (it == pos[i][j]) it--;
        }
        if (it < 0) continue;
        kq = max(kq,i+a[it]);
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