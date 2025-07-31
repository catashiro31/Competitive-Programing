#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
vector<int> segtree[MAXN*4];
int a[MAXN];
void build(int id, int l, int r) {
    if (l == r) {
        segtree[id].psb(a[l]);
        return;
    }
    int m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    int i = 0, j = 0;
    while (i < sz(segtree[id*2]) && j < sz(segtree[id*2+1])) {
        if (segtree[id*2][i] <= segtree[id*2+1][j]) {
            segtree[id].psb(segtree[id*2][i]);
            ++i;
        } else {
            segtree[id].psb(segtree[id*2+1][j]);
            ++j;
        }
    }
    while (i < sz(segtree[id*2])) {
        segtree[id].psb(segtree[id*2][i]);
        ++i;
    }
    while (j < sz(segtree[id*2+1])) {
        segtree[id].psb(segtree[id*2+1][j]);
        ++j;
    }
}
pair<int, int> get(int id, int l ,int r, int u, int v, int k) {
    if (r < u || l > v) return {INT_MAX,0};
    if (u <= l && r <= v) {
        auto it1 = lb(all(segtree[id]),k);
        if (it1 == segtree[id].begin()) {
            int cnt = ub(all(segtree[id]), *it1) - it1;
            return {*it1, cnt};
        }
        if (it1 == segtree[id].end()) {
            auto it2 = it1-1;
            int cnt = it1 - lb(all(segtree[id]), *it2);
            return {*it2, cnt};
        }
        auto it2 = it1-1;
        int val1 = *it2, val2 = *it1;
        if (abs(k - val1) <= abs(k - val2)) {
            int cnt = it1 - lb(all(segtree[id]), val1);
            return {val1, cnt};
        } else {
            int cnt = ub(all(segtree[id]), val2) - it1;
            return {val2, cnt};
        }
    }
    int m = (l+r)/2;
    auto tmp1 = get(id*2,l,m,u,v,k);
    auto tmp2 = get(id*2+1,m+1,r,u,v,k); 
    if (tmp1.fi == INT_MAX) return tmp2;
    if (tmp2.fi == INT_MAX) return tmp1;
    
	if (tmp1.fi == tmp2.fi) return {tmp1.fi, tmp1.se + tmp2.se};
    if (abs(k - tmp1.fi) < abs(k - tmp2.fi)) return tmp1;
    else if (abs(k-tmp1.fi) > abs(k-tmp2.fi)) return tmp2;
    if (tmp1.fi < tmp2.fi) return tmp1;
    return tmp2;
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--) {
        int x, l, r; cin >> x >> l >> r;
        pair<int, int> kq = get(1,1,n,l,r,x);
        cout << kq.fi << " " << kq.se << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}