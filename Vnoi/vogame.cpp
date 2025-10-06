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
    int n, d; cin >> n >> d;
    vector<int> bit(d+1);
    int red = 0, black = 0;
    for (int i = 0; i < d; i++) {
        cin >> bit[i];
        if (bit[i] == 1) red++;
        else black++;
    }
    bit[d] = 0;
    for (int i = 0; i < d; i++) bit[d] ^= bit[i];
    if (bit[d] == 0) black++;
    else red++;

    int sl = n/(d+1);
    n = n%(d+1);
    red *= sl, black *= sl;
    for (int i = 0; i < n; i++) {
        if (bit[i] == 1) red++;
        else black++;
    }

    if (red == 0) cout << 0 << endl;
    else {
        if (red&1) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}