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
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    int R, C; cin >> R >> C;
    vector<string> grid(R);
    for (string &x : grid) cin >> x;
    vector<vector<int>> group_id(R,vector<int>(C,-1));
    int kq = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') continue;
            if (group_id[i][j] == -1) kq++, group_id[i][j] = kq;
            for (int k = 0; k < 2; k++) {
                int nx = dx[k]+i, ny = dy[k]+j;
                if (nx < R && ny < C) group_id[nx][ny] = group_id[i][j];
            }
        }
    }
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