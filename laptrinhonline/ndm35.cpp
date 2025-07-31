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
const int MAXN = 1e3 + 1;
const string NoF = "Name_of_File";
void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    vector<vector<pair<ll,int>>> dp(n,vector<pair<ll,int>>(m,{-1,INT_MAX}));
    dp[0][0] = {1,0};
    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = dx[k]+x, ny = dy[k]+y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '0') continue;
            if (dp[nx][ny].se-1 > dp[x][y].se) {
                dp[nx][ny] = {dp[x][y].fi,dp[x][y].se+1};
                q.push({nx,ny});
            } else if (dp[nx][ny].se-1 == dp[x][y].se) {
                dp[nx][ny].fi = (dp[nx][ny].fi + dp[x][y].fi)%MOD;
                q.push({nx,ny});
            }
        }
    }
    cout << dp[n-1][m-1].fi << endl << dp[n-1][m-1].se;
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