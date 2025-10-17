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
    ll n, q; cin >> n >> q;
    ll arr[n+1];
    for (ll i = 1; i <= n; i++) cin >> arr[i];
    ll k = log2(n)+1;
    ll cmin[k][n+1], cmax[k][n+1], cgcd[k][n+1], cprev[k][n+1];
    for (ll i = 1; i <= n; i++) cmin[0][i] = cmax[0][i] = arr[i];
    for (ll i = 2; i <= n; i++) cgcd[0][i] = abs(arr[i]-arr[i-1]);
    unordered_map<ll,ll> prv;
    for (ll i = 1; i<= n; i++) {
        if (prv[arr[i]]) cprev[0][i] = prv[arr[i]];
        else cprev[0][i] = 0;
        prv[arr[i]] = i;
    } 
    for (ll i = 1; i < k; i++) {
        for (ll j = 1; j + (1<<i)-1 <= n; j++) {
            cmin[i][j] = min(cmin[i-1][j],cmin[i-1][j+(1<<(i-1))]);
            cmax[i][j] = max(cmax[i-1][j],cmax[i-1][j+(1<<(i-1))]);
            cprev[i][j] = max(cprev[i-1][j],cprev[i-1][j+(1<<(i-1))]);
        }
        for (ll j = 2; j + (1<<i)-1 <= n; j++) {
            cgcd[i][j] = gcd(cgcd[i-1][j], cgcd[i-1][j+(1<<(i-1))]);
        }
    }
    while (q--) {
        ll l, r; cin >> l >> r;
        if (l > r) swap(l,r);
        ll k1 = log2(r-l+1), k2 = log2(r-l);
        ll vmax = max(cmax[k1][l],cmax[k1][r-(1<<k1)+1]);
        ll vmin = min(cmin[k1][l], cmin[k1][r-(1<<k1)+1]);
        ll vgcd = gcd(cgcd[k2][l+1], cgcd[k2][r-(1<<k2)+1]);
        ll vprev = max(cprev[k1][l],cprev[k1][r-(1<<k1)+1]);
        if (r == l) cout << "NO" << endl; 
        else if (((vmax-vmin) == 0) || ((vmax-vmin)%(r-l) != 0) || vprev >= l) cout << "NO" << endl;
        else {
            ll d = (vmax-vmin)/(r-l);
            if (vgcd % d != 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        } 
    }
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}