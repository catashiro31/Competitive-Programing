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
    int n; cin >> n;
    int sl[401][401];
    memset(sl,0,sizeof(sl));
    for (int i = 0; i < n; i++) {
        int x, y, c; cin >> x >> y >> c;
        x += 200, y += 200;
        sl[x][y] = c;
    }
    ll kq = 0;
    for (int i = 0; i <= 400; i++) {
        for (int j = i+1; j <= 400; j++) {
            int a[3] = {0,0,0}, b[3] = {0,0,0};
            for (int k = 0; k <= 400; k++) {
                if ((sl[i][k] == 1 && sl[j][k] == 2) || (sl[i][k] == 2 && sl[j][k] == 1)) a[0]++;
                if ((sl[i][k] == 3 && sl[j][k] == 4) || (sl[i][k] == 4 && sl[j][k] == 3)) b[0]++;
                
                if ((sl[i][k] == 1 && sl[j][k] == 4) || (sl[i][k] == 4 && sl[j][k] == 1)) a[1]++;
                if ((sl[i][k] == 2 && sl[j][k] == 3) || (sl[i][k] == 3 && sl[j][k] == 2)) b[1]++;

                if ((sl[i][k] == 1 && sl[j][k] == 3) || (sl[i][k] == 3 && sl[j][k] == 1)) a[2]++;
                if ((sl[i][k] == 2 && sl[j][k] == 4) || (sl[i][k] == 4 && sl[j][k] == 2)) b[2]++;
            }
            for (int i = 0; i < 3; i++) kq += 1LL*a[i]*b[i];
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