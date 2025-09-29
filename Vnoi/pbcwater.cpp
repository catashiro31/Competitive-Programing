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
    int m,n; cin >> m >> n;
    vector<vector<int>> h(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> h[i][j];
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<bool>> vis(m,vector<bool>(n,false));
    for (int i = 0; i < m; i++) {
        for (int j : {0,n-1}) {
            pq.push({h[i][j],{i,j}});
            vis[i][j] = true;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i : {0,m-1}) {
            if (vis[i][j]) continue;
            pq.push({h[i][j],{i,j}});
            vis[i][j] = true;
        }
    }
    ll ans = 0;
    int di[4] = {1,-1,0,0};
    int dj[4] = {0,0,-1,1};
    while(!pq.empty()) {
        auto [lvl,ij] = pq.top(); pq.pop();
        auto [i,j] = ij;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni<0 || nj<0 || ni>=m || nj>=n || vis[ni][nj]) continue;
            vis[ni][nj] = 1;
            if (h[ni][nj] < lvl) ans += (lvl - h[ni][nj]);
            int nlvl = max(lvl, h[ni][nj]);
            pq.push({nlvl,{ni,nj}});
        }
    }
    cout << ans;
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