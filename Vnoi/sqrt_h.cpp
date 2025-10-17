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

int a[MAXN];
vector<int> segt[4*MAXN];
void build(int id, int l, int r) {
    if (l == r) {
        segt[id].psb(a[l]);
        return;
    }
    int m = (l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    int i = 0, j = 0;
    while (i < sz(segt[id<<1]) && j < sz(segt[id<<1|1])) {
        if (segt[id<<1][i] <= segt[id<<1|1][j]) segt[id].psb(segt[id<<1][i++]);
        else segt[id].psb(segt[id<<1|1][j++]);
    }
    while (j < sz(segt[id<<1|1])) segt[id].psb(segt[id<<1|1][j++]);
    while (i < sz(segt[id<<1])) segt[id].psb(segt[id<<1][i++]);
}

vector<int> get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return {};
    if (u <= l && r <= v) return segt[id];
    int m = (l+r)>>1;
    vector<int> left = get(id<<1,l,m,u,v), right = get(id<<1|1,m+1,r,u,v);
    if (left.empty()) return right;
    if (right.empty()) return left;
    int i = 0, j = 0;
    vector<int> res;
    while (i < sz(left) && j < sz(right)) {
        if (left[i] <= right[j]) res.psb(left[i++]);
        else res.psb(right[j++]);
    }
    while (j < sz(right)) res.psb(right[j++]);
    while (i < sz(left)) res.psb(left[i++]);
    return res;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int q; cin >> q;
    build(1,1,n);
    while (q--) {
        int l, r; cin >> l >> r;
        vector<int> vt = get(1,1,n,l,r);
        int kq = INT_MAX;
        for (int i = 1; i < sz(vt); i++) kq = min(kq,vt[i]-vt[i-1]);
        cout << kq << endl;
    }
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