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
    string s; cin >> s;
    int n = (int)s.size();

    vector<vector<char>> pal(n, vector<char>(n, 0));
    for (int i = 0; i < n; ++i) pal[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            if (s[l] == s[r] && (len == 2 || pal[l+1][r-1])) pal[l][r] = 1;
        }
    }

    vector<vector<char>> super(n, vector<char>(n, 0));
    long long kq = 0;

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;

            if (pal[l][r]) {
                super[l][r] = 1;
            } else {
                for (int k = l+1; k < r-1; ++k) {
                    if (super[l][k] && pal[k+1][r]) {
                        super[l][r] = 1;
                        break;
                    }
                }
            }

            if (super[l][r]) ++kq;
        }
    }

    cout << kq << '\n';
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