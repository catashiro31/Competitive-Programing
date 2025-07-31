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
ll cal(int x, int y) {
    ll ans = 1;
    int cmax = max(x,y);
    if (cmax == x) {
        vector<bool> c(y+1,false);
        for (int i = x+1; i <= x+y; i++) {
            ans *= i;
            for (int j = 1; j <= y; j++) {
                if (c[j]) continue;
                else {
                    if (ans % j == 0) c[j] = true, ans /= j;
                }
            }
        }
    } else {
        vector<bool> c(x,false);
        for (int i = y+1; i <= x+y; i++) {
            ans *= i;
            for (int j = 1; j <= x; j++) {
                if (c[j]) continue;
                else {
                    if (ans % j == 0) c[j] = true, ans /= j;
                }
            }
        }
    }
    return ans;
}
void solve() {
    ll a, b, k; cin >> a >> b >> k;
    string kq = "";
    for (int i = 0; i < a+b; i++) kq+="a";
    for (int i = 0; i < b; i++) {
        for (int j = a+i; j >= 0; j--) {
            if (k-cal(a+i-j,b-1-i) > 0) k -= cal(a+i-j,b-1-i);
            else {
                kq[j] = 'b';
                break;
            }
        }
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