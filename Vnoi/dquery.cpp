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
const int MAXN = 3e4+5;
const string NoF = "Name_of_File";
int a[MAXN];
vector<int> segtree[MAXN*4];
void Build(int id, int l, int r) {
    if (l == r) {
        segtree[id].psb(a[l]);
        return;
    }
    int m = (l+r)/2;
    Build(id*2,l,m);
    Build(id*2+1,m+1,r);
    if (sz(segtree[id*2]) == 0) segtree[id] = segtree[id*2+1];
    else if (sz(segtree[id*2+1]) == 0) segtree[id] = segtree[id*2];
    else {
        int i = 0, j = 0;
        while(i < sz(segtree[id*2]) && j < sz(segtree[id*2+1])) {
            if (segtree[id*2][i] < segtree[id*2+1][j]) {
                segtree[id].psb(segtree[id*2][i]);
                i++;
            } else if (segtree[id*2][i] > segtree[id*2+1][j]) {
                segtree[id].psb(segtree[id*2+1][j]);
                j++;
            } else {
                int val = segtree[id*2][i];
                segtree[id].psb(val);
                while (i < sz(segtree[id*2]) && segtree[id*2][i] == val) i++;
                while (j < sz(segtree[id*2+1]) && segtree[id*2+1][j] == val) j++;
            }
            if (i == sz(segtree[id*2])) while(j < sz(segtree[id*2+1])) {segtree[id].psb(segtree[id*2+1][j]); j++;}
            if (j == sz(segtree[id*2+1])) while (i < sz(segtree[id*2])) {segtree[id].psb(segtree[id*2][i]); i++;}
        }
    }
}
vector<int> Get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return {};
    if (u <= l && r <= v) return segtree[id];
    int m = (l+r)/2;
    vector<int> arr1 = Get(id*2,l,m,u,v), arr2 = Get(id*2+1,m+1,r,u,v);
    if (sz(arr1) == 0) return arr2;
    if (sz(arr2) == 0) return arr1;
    vector<int> ans;
    int i = 0, j = 0;
    while(i < sz(arr1) && j < sz(arr2)) {
        if (arr1[i] < arr2[j]) {
            ans.psb(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            ans.psb(arr2[j]);
            j++;
        } else {
            int val = arr1[i];
            ans.psb(val);
            while (i < sz(arr1) && arr1[i] == val) i++;
            while (j < sz(arr2) && arr2[j] == val) j++;
        }
        if (i == sz(arr1)) while(j < sz(arr2)) {ans.psb(arr2[j]); j++;}
        if (j == sz(arr2)) while (i < sz(arr1)) {ans.psb(arr1[i]); i++;}
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Build(1,1,n);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << sz(Get(1,1,n,u,v)) << endl;
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