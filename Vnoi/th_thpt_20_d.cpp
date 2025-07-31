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
    string s; cin >> s;
    int n = sz(s);
    vector<int> nguyen(n), phu(n);
    if (n == 1) cout << 0;
    else {
        nguyen[n-1] = 0, phu[n-1] = 0;
        if (s[n-1] == 'u' || s[n-1] == 'e' || s[n-1] == 'o' || s[n-1] == 'a' || s[n-1] == 'i') nguyen[n-2] = 1, phu[n-2] = 0;
        else nguyen[n-2] = 0, phu[n-2] = 1;
        for (int i = n-3; i >= 0; i--) {
            if (s[i+1] == 'u' || s[i+1] == 'e' || s[i+1] == 'o' || s[i+1] == 'a' || s[i+1] == 'i') nguyen[i] = nguyen[i+1] + 1, phu[i] = phu[i+1];
            else nguyen[i] = nguyen[i+1], phu[i] = phu[i+1] + 1;
        }
        ll kq = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i') kq += phu[i];
            else kq += nguyen[i];
        }
        cout << kq;
    }
}
    
int main() {
// #ifndef ONLINE_JUDGE
    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}
