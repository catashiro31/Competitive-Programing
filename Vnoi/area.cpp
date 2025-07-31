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
const int MAXY = 3e4;
const string NoF = "Name_of_File";
pair<int,int> segtree[MAXY*4+5];
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        segtree[id].se += val;
        if (segtree[id].se != 0) segtree[id].fi = r - l + 1;
        else if (l != r) segtree[id].fi = segtree[id * 2].fi + segtree[id * 2 + 1].fi;
        else segtree[id].fi = 0;
        return;
    }

    int m = (l + r) >> 1;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);

    if (segtree[id].se != 0) segtree[id].fi = r - l + 1;
    else segtree[id].fi = segtree[id * 2].fi + segtree[id * 2 + 1].fi;
}

void solve() {
    int n; cin >> n;
    vector<pair<pair<int,int>,pair<int,int>>> arr;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        arr.psb({{y1,1},{x1,x2}});
        arr.psb({{y2,-1},{x1,x2}});
    }
    sort(all(arr));
    for (int id = 0; id < MAXY*4; id++) segtree[id] = {0,0};
    int i = 0, kq = 0;
    for (int y = 0; y < MAXY; y++) {
        while (i < sz(arr) && arr[i].fi.fi == y) {
            update(1,0,MAXY-1,arr[i].se.fi,arr[i].se.se-1,arr[i].fi.se);
            i++;
        }
        kq += segtree[1].fi;
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