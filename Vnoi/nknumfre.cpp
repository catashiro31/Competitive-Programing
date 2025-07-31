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
int GCD(int x, int y) {
    if (y == 0) return x;
    return GCD(y,x%y);
}
void solve() {
    int a, b; cin >> a >> b;
    int kq = 0;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        int nub_1 = i, nub_2 = 0;
        for (int j = sz(s)-1; j >= 0; j--) nub_2 = nub_2*10 + (s[j]-'0');
        if (GCD(nub_1,nub_2) == 1) kq++;
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