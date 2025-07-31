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
const int MAXN = 2e5 + 1;
const string NoF = "Name_of_File";
int par[MAXN];
int Find(int u) {
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}
int temp = 0, kq = INT_MIN;
void Try(int i, int size, bool &c,vector<pair<int,pair<int,int>>> edge) {
    if (i == size) {
        kq = max(kq,temp);
        return;
    }
    int pu = Find(edge[i].se.fi), pv = Find(edge[i].se.se);
    if (pu > pv) swap(pu,pv);
    if (pu != pv) {
        if (c) {
            temp += edge[i].fi;
            par[pv] = pu;
            Try(i+1,size,c,edge);
            par[pv] = pv;
            temp -= edge[i].fi;
        } else {
            c = true;
            Try(i+1,size,c,edge);
            c = false;
            temp += edge[i].fi;
            par[pv] = pu;
            Try(i+1,size,c,edge);
            par[pv] = pv;
            temp -= edge[i].fi;
        }
    } else Try(i+1,size,c,edge);
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i; 
    vector<pair<int,pair<int,int>>> edge(m);
    for (auto &[x,e] : edge) {
        auto &[u,v] = e;
        cin >> u >> v >> x;
    }
    sort(all(edge));
    bool c = false;
    Try(0,m,c,edge);
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