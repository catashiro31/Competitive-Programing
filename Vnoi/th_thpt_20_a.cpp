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
const string NoF = "CAU1";
ll GCD(ll a,ll b) {
    if (b == 0) return a;
    return GCD(b,a%b);
}    
void solve() {
    ll x, y; cin >> x >> y;
    ll max_n = GCD(x,y);
    ll kq = 0;
    for (int i = 1; i*i <= max_n; i++) {
        if (max_n % i != 0) continue;
        ll low = i, high = max_n/i;
        if (low < high) kq += 2;
        else kq++;
    }
    cout << kq << "\n";
}
    
int main() {
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}