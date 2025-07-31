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
vector<vector<ll>> Multi_Matrix(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> ans(sz(A),vector<ll>(sz(B[0]),0));
    for (int i = 0; i < sz(A); i++) {
        for (int j = 0; j < sz(B[0]); j++) {
            for (int k = 0; k < sz(B); k++) ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])%MOD;
        }
    }
    return ans;
}    
vector<vector<ll>> Pow_Matrix(vector<vector<ll>> base, ll exp) {
    vector<vector<ll>> ans(sz(base),vector<ll>(sz(base),0));
    for (int i = 0; i < sz(base); i++) ans[i][i] = 1;
    while (exp) {
        if (exp & 1) ans = Multi_Matrix(ans,base);
        base = Multi_Matrix(base,base);
        exp /= 2;
    }
    return ans;
}
void solve() {
    ll n; cin >> n;
    vector<vector<ll>> FS(2,vector<ll>(2));
    FS[0][0] = 1, FS[0][1] = 0;
    FS[1][0] = 19, FS[1][1] = 7;
    vector<vector<ll>> temp(2,vector<ll>(2));
    temp[0][0] = 19, temp[0][1] = 7;
    temp[1][0] = 6, temp[1][1] = 20;
    cout << Multi_Matrix(FS,Pow_Matrix(temp,n-1))[1][0];
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