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
void Rotate(int &x, int &y) {
    if (x == 0 && y == 1) x = 1, y = 0;
    else if (x == 1 && y == 0) x = 0, y = -1;
    else if (x == 0 && y == -1) x = -1, y = 0;
    else x = 0, y = 1;
}
void DFS(vector<vector<int>> &grid, int x, int y, int val, int dx, int dy, int n) {
    grid[x][y] = val;
    if (val == 0) return;
    if (x+dx < 0 || x+dx >= n || y+dy < 0 || y+dy >= n || grid[x+dx][y+dy] != -1) Rotate(dx,dy);
    // cout << dx << " " << dy << endl;
    DFS(grid,x+dx,y+dy,val-1,dx,dy,n);
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> grid(n,vector<int>(n,-1));
    DFS(grid,0,0,n*n-1,0,1,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
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