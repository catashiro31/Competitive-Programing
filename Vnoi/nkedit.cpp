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
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
    
void solve() {
    int k; cin >> k;
    string s, p; cin >> s >> p;
    int i = 0;
    while (true) {
        int minlen = min(sz(s),sz(p));
        if (minlen < k) break;
        bool c = false;
        for (int i = minlen; i >= k; i--) {
            for (int j = 0; j + i <= sz(s); j++) {
                string stmp = s.substr(j,i);
                for (int h = 0; h + i <= sz(p); h++) {
                    string ptmp = p.substr(h,i);
                    if (stmp == ptmp) {
                        s.erase(j,i);
                        p.erase(h,i);
                        c = true;
                    }
                    if (c) break;
                }
                if (c) break;
            }
            if (c) break;
        }
        if (!c) break;
        i++;
    }
    cout << i << endl;
    cout << s << endl;
    cout << p << endl;
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