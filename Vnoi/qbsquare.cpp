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
    int m, n; cin >> m >> n;
    vector<vector<int>> board(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    vector<vector<int>> prefix2D(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) prefix2D[i][j] = board[i][j];
            else if (i == 0) prefix2D[i][j] = prefix2D[i][j-1] + board[i][j];
            else if (j == 0) prefix2D[i][j] = prefix2D[i-1][j] + board[i][j];
            else prefix2D[i][j] = prefix2D[i][j-1] + prefix2D[i-1][j] - prefix2D[i-1][j-1] + board[i][j];
        }
    }
    int l = 1, r = min(m,n);
    int kq = INT_MIN;
    while (l <= r) {
        int md = (l+r)/2;
        bool c = false;
        for (int i = 0; i <= m-md; i++) {
            for (int j = 0; j <= n-md; j++) {
                int x = i+md-1, y = j+md-1;
                int tmp = -1;
                if (i == 0 && j == 0) tmp = prefix2D[x][y];
                else if (i == 0) tmp = prefix2D[x][y] - prefix2D[x][j-1];
                else if (j == 0) tmp = prefix2D[x][y] - prefix2D[i-1][y];
                else tmp = prefix2D[x][y] - prefix2D[x][j-1] - prefix2D[i-1][y] + prefix2D[i-1][j-1];
                if (tmp == 0 || tmp == md*md) {c = true; break;}
            }
            if (c) break;
        }
        if (c) kq = max(kq,md), l = md+1;
        else r = md-1;
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