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
int segtree[4*MAXN], a[MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        segtree[id] = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    segtree[id] = min(segtree[id<<1],segtree[id<<1|1]);
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return INT_MAX;
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r) >> 1;
    int g1 = get(id<<1,l,m,u,v), g2 = get(id<<1|1,m+1,r,u,v);
    return min(g1, g2);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    int left = INT_MIN, right = INT_MIN;
    build(1,1,n);
    while (l + 1 < r) {
        left = max(left, a[l]), right = max(right, a[r]);
        if (left < right) l++;
        else if (right < left) r--;
        else {
            int lr = get(1,1,n,l+1,r-1);
            if (lr == left) {
                cout << "YES" << endl;
                cout << l << " " << r-l-1 << " " << n-r+1 << endl;
                return;
            } else {
                if (a[l+1] <= a[r-1]) l++;
                else r--;
            }
        }
    }
    cout << "NO" << endl;
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}