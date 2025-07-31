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
int n;
int GET(int x, vector<int> &FWT) {
    int ans = 0;
    while(x) {
        ans += FWT[x];
        x -= x & (-x);
    }
    return ans;
}
void UPDATE(int x, vector<int> &FWT) {
    while(x < n+1) {
        FWT[x]++;
        x += x & (-x);
    }
}
void solve() {
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) odd.psb(a[i]);
        else even.psb(a[i]);
    }
    int invension_cnt = 0;
    vector<int> BIT1(n+1,0), BIT2(n+1,0);
    for (int i = sz(odd)-1; i >= 0; i--) invension_cnt += GET(odd[i]-1,BIT1), UPDATE(odd[i],BIT1);
    for (int i = sz(even)-1; i >= 0; i--) invension_cnt += GET(even[i]-1,BIT2), UPDATE(even[i],BIT2);
    sort(all(odd));
    sort(all(even));
    vector<int> kq(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) kq[i] = odd[i/2];
        else kq[i] = even[i/2];
    }
    if (invension_cnt % 2 == 0) {
        for (int x : kq) cout << x << " ";
        cout << endl;
    } else {
        swap(kq[n-3],kq[n-1]);
        for (int x : kq) cout << x << " ";
        cout << endl;
    }
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