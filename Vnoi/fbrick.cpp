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

vector<vector<ll>> multi_mat(const vector<vector<ll>> &A, const vector<vector<ll>> &B, ll m) {
    vector<vector<ll>> res(sz(A), vector<ll>(sz(B[0])));
    for (int i = 0; i < sz(A); i++) {
        for (int j = 0; j < sz(B[0]); j++) {
            res[i][j] = 0;
            for (int k = 0; k < sz(A[0]); k++) {
                res[i][j] = (res[i][j] + A[i][k]*B[k][j]) % m;
            }
        }
    }
    return res;
}

vector<vector<ll>> exp_mat(vector<vector<ll>> base, ll exp, ll m) {
    vector<vector<ll>> res(sz(base), vector<ll>(sz(base),0));
    for (int i = 0; i < sz(base); i++) res[i][i] = 1;
    while(exp) {
        if (exp&1) res = multi_mat(res,base,m);
        base = multi_mat(base,base,m);
        exp /= 2;
    }
    return res;
}

void solve() {
    ll t, n, m; cin >> t >> n >> m;
    
    vector<vector<ll>> base(1,vector<ll>(4));
    base[0][0] = 1%m;
    base[0][1] = (t*t)%m;
    base[0][2] = (1*t)%m;
    base[0][3] = (base[0][0] + base[0][1])%m;
    
    vector<vector<ll>> mat(4, vector<ll>(4,0));
    mat[1][0] = 1, mat[0][1] = 1, mat[1][1] = (4LL*t*t)%m;
    mat[2][1] = ((-4LL*t)%m+m)%m, mat[1][2] = (2*t)%m, mat[2][2] = ((-1%m)+m)%m;
    mat[0][3] = 1, mat[1][3] = (4LL*t*t)%m, mat[2][3] = ((-4LL*t)%m+m)%m, mat[3][3] = 1; 

    vector<vector<ll>> kq = multi_mat(base, exp_mat(mat, n-2, m), m);
    cout << kq[0][3] << endl;
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}