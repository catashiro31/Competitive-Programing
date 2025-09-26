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
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(all(a));
    ll tong = 0, nhon = 0, vuong = 0;

    vector<ll> sq(n);
    for (ll i = 0; i < n; i++) sq[i] = a[i] * a[i];
    for (ll k = 2; k < n; ++k) {
        ll i = 0, j = k - 1;
        while (i < j) {
            if (a[i] + a[j] > a[k]) { tong += (j - i); --j; }
            else ++i;
        }
    }

    for (ll k = 2; k < n; ++k) {
        ll i = 0, j = k - 1;
        long long c2 = sq[k];
        while (i < j) {
            long long s = sq[i] + sq[j];
            if (s > c2) { nhon += (j - i); --j; }
            else ++i;
        }
    }

    for (ll k = 2; k < n; ++k) {
        ll i = 0, j = k - 1;
        long long c2 = sq[k];
        while (i < j) {
            long long s = sq[i] + sq[j];
            if (s == c2) {
                ll ii = i + 1, jj = j - 1;
                while (ii <= j && sq[ii] == sq[i]) ++ii;
                while (jj >= i && sq[jj] == sq[j]) --jj;
                vuong += 1LL * (ii - i) * (j - jj);
                i = ii; j = jj;
            } else if (s < c2) {
                ++i;
            } else {
                --j;
            }
        }
    }

    long long tu = tong - nhon - vuong;
    cout << nhon << ' ' << vuong << ' ' << tu << '\n';
}
    
int main() {
    freopen("CAU5.INP", "r", stdin);
    freopen("CAU5.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}