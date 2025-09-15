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
    vector<pair<int,int>> we;
    int kq = 1;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x == y) kq = max(kq,x);
        else we.psb({x,y}); 
    }
    sort(all(we));
    pair<int,int> go = {1,1};
    kq--;
    for (int i = 0; i < sz(we); i++) {
        if ((go.fi+go.se) % 2 == 0) {
            if (we[i].fi - we[i].se == go.fi - go.se) {
                kq += we[i].fi - go.fi;
                go = we[i];
                continue;
            } else go = {go.fi+1, go.se};
        }
        int d1 = we[i].se - go.se;
        go = {go.fi+d1, go.se+d1};
        if (go == we[i]) continue;
        int d2 = we[i].fi - go.fi;
        kq += (d2+1)/2;
        go = we[i];
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