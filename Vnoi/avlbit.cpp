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
const int MAXN = 1e5 + 1;
const string NoF = "Name_of_File";
struct mimasu {
    ll cmin, cmax, csum;
};
struct mimagcd {
    ll cmin, cmax, cgcd;
};
mimasu init1;
mimagcd init2;
mimasu segtree[4*MAXN];
mimagcd segdiff[4*MAXN];
ll a[MAXN], diff[MAXN];
void build(int id, int l, int r) {
    if (l == r) {
        segtree[id].cmin = a[l];
        segtree[id].cmax = a[l];
        segtree[id].csum = a[l];
        segdiff[id].cmin = diff[l];
        segdiff[id].cmax = diff[l];
        segdiff[id].cgcd = diff[l];
        return;
    }
    int m = (l+r)>>1;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);
    segtree[id].cmin = min(segtree[id<<1].cmin, segtree[id<<1|1].cmin);
    segtree[id].cmax = max(segtree[id<<1].cmax, segtree[id<<1|1].cmax);
    segtree[id].csum = segtree[id<<1].csum + segtree[id<<1|1].csum;
    segdiff[id].cmin = min(segdiff[id<<1].cmin, segdiff[id<<1|1].cmin);
    segdiff[id].cmax = max(segdiff[id<<1].cmax, segdiff[id<<1|1].cmax);
    segdiff[id].cgcd = gcd(segdiff[id<<1].cgcd,segdiff[id<<1|1].cgcd);
}

mimasu get1(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return init1;
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)>>1;
    mimasu g1 = get1(id<<1,l,m,u,v), g2 = get1(id<<1|1,m+1,r,u,v);
    mimasu res;
    res.cmin = min(g1.cmin, g2.cmin);
    res.cmax = max(g1.cmax, g2.cmax);
    res.csum = g1.csum + g2.csum;
    return res;
}

mimagcd get2(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return init2;
    if (u <= l && r <= v) return segdiff[id];
    int m = (l+r)>>1;
    mimagcd g1 = get2(id<<1,l,m,u,v), g2 = get2(id<<1|1,m+1,r,u,v);
    mimagcd res;
    res.cmin = min(g1.cmin, g2.cmin);
    res.cmax = max(g1.cmax, g2.cmax);
    res.cgcd = gcd(g1.cgcd, g2.cgcd);
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    diff[1]  = 0;
    for (int i = 2; i <= n; i++) diff[i] = abs(a[i-1] - a[i]);
    build(1,1,n);
    init1.cmin = LLONG_MAX, init1.cmax = LLONG_MIN, init1.csum = 0;
    init2.cmin = LLONG_MAX, init2.cmax = LLONG_MAX, init2.cgcd = 0;
    while (m--) {
        ll u, v; cin >> u >> v;
        if (v - u <= 1LL) cout << "YES" << endl;
        else {
            mimasu inf = get1(1,1,n,u,v);
            ll sl = v - u + 1;
            if ((inf.cmax - inf.cmin) % (sl-1) != 0) cout << "NO" << endl;
            else if (inf.cmax == inf.cmin) cout << "NO" << endl;
            else {
                ll cs = (inf.cmax - inf.cmin) / (sl-1);
                if (((inf.csum - sl*inf.cmin) % (1LL*(sl-1)*sl/2) != 0) || ((inf.csum - sl*inf.cmin) / (1LL*(sl-1)*sl/2) != cs)) cout << "NO"<< endl;
                else {
                    mimagcd dif = get2(1,1,n,u+1,v);
                    if (dif.cgcd % cs != 0 || dif.cmin < cs) cout << "NO" << endl;
                    else cout << "YES" << endl;
                }
            }
        }
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