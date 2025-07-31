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
const int MAXN = 5e4+5;
const string NoF = "Name_of_File";
struct node {
    int sum, maxsuffix, maxprefix, maxsub;
};
node segtree[MAXN*4];
int a[MAXN];
void Build(int id, int l, int r) {
    if (l == r) {
        segtree[id].maxprefix = a[l];
        segtree[id].sum = a[l];
        segtree[id].maxsub = a[l];
        segtree[id].maxsuffix = a[l];
        return;
    }
    int m = (l+r)/2;
    Build(id*2,l,m);
    Build(id*2+1,m+1,r);
    segtree[id].maxprefix = max(segtree[id*2].maxprefix,segtree[id*2].sum+segtree[id*2+1].maxprefix);
    segtree[id].maxsuffix = max(segtree[id*2+1].maxsuffix,segtree[id*2+1].sum+segtree[id*2].maxsuffix);
    segtree[id].sum = segtree[id*2].sum + segtree[id*2+1].sum;
    segtree[id].maxsub = max(max(segtree[id*2].maxsub,segtree[id*2+1].maxsub),segtree[id*2].maxsuffix+segtree[id*2+1].maxprefix);
    return;
}
node Get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return node{0,INT_MIN,INT_MIN,INT_MIN};
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)/2;
    node n1 = Get(id*2,l,m,u,v), n2 = Get(id*2+1,m+1,r,u,v);
    if (n1.maxsub == INT_MIN) return n2;
    if (n2.maxsub == INT_MIN) return n1;
    node ans;
    ans.sum = n1.sum + n2.sum;
    ans.maxprefix = max(n1.maxprefix,n1.sum+n2.maxprefix);
    ans.maxsuffix = max(n2.maxsuffix,n2.sum+n1.maxsuffix);
    ans.maxsub = max(max(n1.maxsub,n2.maxsub),n1.maxsuffix+n2.maxprefix);
    return ans;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Build(1,1,n);
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        cout << Get(1,1,n,x,y).maxsub << endl;
    }
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