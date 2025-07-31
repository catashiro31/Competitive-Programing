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
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int kq = 0;
void DFS(int x, int y, int st, vector<vector<int>> &c, const vector<string> &grid) {
    if (st == -1) {
        if (!c[x][y]) kq++;
        c[x][y] = 2;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k]+x, ny = dy[k]+y;
            if (grid[nx][ny] == '#') continue;
            DFS(x,y,k,c,grid);
        } 
    } else {
        int nx = dx[st]+x, ny = dy[st]+y;
        if (grid[nx][ny] == '#') {
            if (c[x][y] == 2) return;
            DFS(x,y,-1,c,grid);
        } else {
            if (!c[nx][ny]) kq++, c[nx][ny] = 1;
            DFS(nx,ny,st,c,grid);
        }
    }
}    
void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    vector<vector<int>> c(n,vector(m,0));
    DFS(1,1,-1,c,grid);
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