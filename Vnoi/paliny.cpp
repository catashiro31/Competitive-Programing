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
const int MAXN = 5e4 + 5;
const string NoF = "Name_of_File";
ll base[MAXN], hashS[MAXN], hashR[MAXN];
int n;
ll gethashS(int u, int v) {
    return (hashS[v]-(hashS[u-1]*base[v-u+1])%MOD+MOD)%MOD;
}
ll gethashR(int u, int v) {
    return (hashR[v]-(hashR[u-1]*base[v-u+1])%MOD+MOD)%MOD;
}
bool check(int m) {
    for (int i = 1; i+m-1 <= n; i++) {
        if (gethashS(i,i+m-1) == gethashR(n-i-m+2,n-i+1)) return true;
    }
    return false;
}
void solve() {
    cin >> n;
    string s; cin >> s;
    string rs = s; reverse(all(rs));
    s = " " + s;
    rs = " " + rs;
    base[0] = 1, hashS[0] = 0, hashR[0] = 0;
    for (int i = 1; i <= n; i++) {
        base[i] = (base[i-1]*31)%MOD;
        hashS[i] = (hashS[i-1]*31+s[i]-'a'+1)%MOD;
        hashR[i] = (hashR[i-1]*31+rs[i]-'a'+1)%MOD;
    }
    int kq = INT_MIN;
    int l = 1, r = n - (n%2 == 0);
    while (l <= r) {
        int m = (r+l)/2;
        if (m % 2 == 0) m++;
        if (check(m)) kq = max(kq,m), l = m+2;
        else r = m-2;
    }
    l = 2, r = n- (n%2 == 1);
    while (l <= r) {
        int m = (r+l)/2;
        if (m % 2 == 1) m++;
        if (check(m)) kq = max(kq,m), l = m+2;
        else r = m-2;
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
