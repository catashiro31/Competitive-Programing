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
int BIT[MAXN];
void Update(int x) {
    while (x < MAXN) {
        BIT[x]++;
        x += x & (-x);
    }
}
int Get(int x) {
    int ans = 0;
    while (x) {
        ans += BIT[x];
        x -= x &(-x);
    }
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < MAXN; i++) BIT[i] = 0;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int kq = 0;
    for (int i = n-1; i >= 0; i--) {
        kq += Get(a[i]-1);
        Update(a[i]);
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