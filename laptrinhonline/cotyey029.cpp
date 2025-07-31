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
string s, tmp = "";
ll kq = 0;
void Try(int i) {
    if (i == sz(s)) {
        ll val = 0;
        for (int j = 0; j < sz(tmp); j++) {
            if (tmp[j] == '+') {
                kq += val, val = 0;
                continue;
            }
            val = val*10LL+(tmp[j]-'0');
        }
        kq += val;
        return;
    }
    if (sz(tmp) > 0 && tmp[sz(tmp)-1] != '+') {
        tmp = tmp + "+" + s[i];
        Try(i+1);
        tmp.ppb(), tmp.ppb();   
    }
    tmp += s[i];
    Try(i+1);
    tmp.ppb();
}
void solve() {
    cin >> s;
    Try(0);
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