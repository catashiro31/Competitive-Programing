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
vector<int> BIT1(MAXN,0), BIT2(MAXN,0);
void update1(int x, int val) {
    for (; x > 0; x -= x & (-x))
        BIT1[x] = max(BIT1[x], val);
}

void update2(int x, int val) {
    for (; x <= n; x += x & (-x))
        BIT2[x] = max(BIT2[x], val);
}

int query1(int x) {
    int ans = 0;
    for (; x <= n; x += x & (-x))
        ans = max(ans, BIT1[x]);
    return ans;
}

int query2(int x) {
    int ans = 0;
    for (; x > 0; x -= x & (-x))
        ans = max(ans, BIT2[x]);
    return ans;
}
void solve() {
    cin >> n;
    vector<int> val, a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        val.psb(a[i]);
    }
    sort(all(val));

    for (int i = 0; i < n; i++)
        a[i] = lb(all(val), a[i]) - val.begin() + 1;
    vector<int> lis(n), lds(n);
    for (int i = n-1; i >= 0; i--) {
        lds[i] = 1 + query1(a[i]+1);
        lis[i] = 1 + query2(a[i]-1);
        update2(a[i],lis[i]); update1(a[i],lds[i]);
    }
    int kq = INT_MIN;
    for (int i = 0; i < n; i++) {
        kq = max(kq,lds[i]+lis[i]-1);
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