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
    
void solve() {
    int n, sl[2]; cin >> n >> sl[0] >> sl[1];
    vector<pair<int,int>> dk(n);
    for (auto &x : dk) cin >> x.fi >> x.se;
    sort(all(dk));
    int kq = INT_MAX;
    int i = 0, j = 0;
    int cur[2] = {0,0};
    while (j < n) {
        cur[dk[j].se-1]++;
        while(i < j && cur[dk[i].se-1]-1 >= sl[dk[i].se-1]) cur[dk[i].se-1]--, i++;
        if (cur[0] >= sl[0] && cur[1] >= sl[1]) kq = min(kq,dk[j].fi-dk[i].fi);
        j++;
    }
    if (kq == INT_MAX) cout << -1;
    else cout << kq;
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