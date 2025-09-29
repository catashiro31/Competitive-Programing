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
    int n, m; cin >> n >> m;
    int a[n+1], cnt[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(cnt,0,sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        if (a[i] <= n) cnt[a[i]]++;
    }
    vector<int> val;
    vector<vector<int>> prefix_sums;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= i) {
            val.psb(i);
            vector<int> prefix_sum(n+1,0);
            for (int j = 1; j <= n; j++) prefix_sum[j] = prefix_sum[j-1] + (a[j] == i);
            prefix_sums.psb(prefix_sum); 
        }
    }
    while(m--) {
        int l, r; cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < sz(val); i++) {
            if (prefix_sums[i][r] - prefix_sums[i][l-1] == val[i]) ans++;
        }
        cout << ans << endl;
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