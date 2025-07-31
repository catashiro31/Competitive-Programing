#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
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
    int t; cin >> t;
    const ull gh = 3e6;
    vector<ull> prime;
    vector<bool> c(gh + 1, false);
    for (ull i = 2; i <= gh; i++) {
        if (c[i]) continue;
        prime.psb(i);
        for (ull j = i * i; j <= gh; j += i) c[j] = true;
    }
    vector<ull> val[11];
    for (int i = 3; i <= 10; i++) {
        for (int j = 0; j + i <= sz(prime); j++) {
            ull cal = 1;
            bool tran = false;
            for (int k = 0; k < i; k++) {
                if (cal > ULLONG_MAX / prime[j + k]) {
                    tran = true;
                    break;
                }
                cal *= prime[j + k];
            }
            if (tran) break;
            val[i].psb(cal);
        }
    }
    while (t--) {
        ull n; cin >> n;
        int k; cin >> k;
        int pos = ub(all(val[k]), n) - val[k].begin();
        if (pos == 0) cout << -1 << endl;
        else cout << val[k][pos - 1] << endl;
    }
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