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
    int n, k; cin >> n >> k;
    vector<vector<int>> board(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    vector<vector<int>> prefix2D(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {prefix2D[i][j] = board[i][j]; continue;}
            else if (i > 0 && j > 0) prefix2D[i][j] = prefix2D[i-1][j]+prefix2D[i][j-1]-prefix2D[i-1][j-1]+board[i][j];
            else if (i > 0) prefix2D[i][j] = prefix2D[i-1][j] + board[i][j];
            else if (j > 0) prefix2D[i][j] = prefix2D[i][j-1] + board[i][j];
        }
    }
    int kq = INT_MIN;
    for (int i = k-1; i < n; i++) {
        for (int j = k-1; j < n; j++) {
            int x = i-k, y = j-k;
            if (x < 0 || y < 0) {
                if (x >= 0) kq = max(kq,prefix2D[i][j]-prefix2D[x][j]);
                if (y >= 0) kq = max(kq,prefix2D[i][j]-prefix2D[i][y]); 
            } else kq = max(kq,prefix2D[i][j]-prefix2D[x][j]-prefix2D[i][y]+prefix2D[x][y]);
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