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
const int MOD = 5e6;
const int MAXN = 1e4 + 5;
const string NoF = "Name_of_File";
int BIT[55][MAXN];

void update(int id, int x, int val) {
    while (x < MAXN) {
        BIT[id][x] = (BIT[id][x] + val) % MOD;
        x += x&(-x);
    }
}
int get(int id, int x) {
    int res = 0;
    while (x) {
        res = (res + BIT[id][x]) % MOD;
        x -= x&(-x);
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> a = s;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    auto rank_of = [&](int v){
        return int(lower_bound(a.begin(), a.end(), v) - a.begin()) + 1;
    };
    for (int i = 0; i < n; ++i) s[i] = rank_of(s[i]); 
    int dp[n][k+5];
    memset(BIT, 0, sizeof(BIT));
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
        update(1,s[i],1);
        for (int j = 2; j <= k; j++) {
            dp[i][j] = get(j-1, s[i]-1);
            update(j,s[i],dp[i][j]);
        }
    }
    int kq = 0;
    for (int i = 0; i < n; i++) kq = (kq + dp[i][k])%MOD;
    cout << kq;
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