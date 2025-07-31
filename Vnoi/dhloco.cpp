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
ll modulo;
vector<vector<ll>> multiple(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> ans(sz(a),vector<ll>(sz(b[0])));
    for (int i = 0; i < sz(a); i++) {
        for (int j = 0; j < sz(b[0]); j++) {
            ans[i][j] = 0;
            for (int k = 0; k < sz(a[0]); k++) ans[i][j] = (ans[i][j]+a[i][k]*b[k][j])%modulo;
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>> base, ll exp) {
    vector<vector<ll>> ans(sz(base),vector<ll>(sz(base),0));
    for (int i = 0; i < sz(base); i++) ans[i][i] = 1;
    while (exp) {
        if (exp&1) ans = multiple(ans,base);
        base = multiple(base,base);
        exp /= 2;
    }
    return ans;
}
void solve() {
    ll n, m; cin >> n >> m;
    modulo = m;
    vector<vector<ll>> f(1,vector<ll>(3));
    f[0][0] = 1, f[0][1] = 1, f[0][2] = 2;
    vector<vector<ll>> base(3,vector<ll>(3,0));
    base[1][0] = base[2][1] = base[0][2] = base[1][2] = base[2][2] = 1;
    vector<vector<ll>> dp = multiple(f,power(base,n));
    cout << dp[0][0];
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