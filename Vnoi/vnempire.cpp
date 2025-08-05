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
int par[MAXN];
int _find(int u) {
    if (par[u] == u) return u;
    return par[u] = _find(par[u]);
}
bool _union(int u, int v) {
    int pu = _find(u), pv = _find(v);
    if (pu == pv) return false;
    if (pu < pv) swap(pu,pv);
    par[pu] = pv;
    return true;
}
void solve() {
    int n; cin >> n;
    ll x[n], y[n], z[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    set<pair<int,int>> sx, sy, sz;
    for (int i = 0; i < n; i++) sx.insert({x[i],i}), sy.insert({y[i],i}), sz.insert({z[i],i});
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        auto it1 = sx.lb({x[i],i});
        if (it1 != sx.begin()) pq.push({abs(x[i]-(*prev(it1)).fi),{i,(*prev(it1)).se}});
        it1++;
        if (it1 != sx.end()) pq.push({abs(x[i]-(*it1).fi),{i,(*it1).se}});

        auto it2 = sy.lb({y[i],i});
        if (it2 != sy.begin()) pq.push({abs(y[i]-(*prev(it2)).fi),{i,(*prev(it2)).se}});
        it2++;
        if (it2 != sy.end()) pq.push({abs(y[i]-(*it2).fi),{i,(*it2).se}});

        auto it3 = sz.lb({z[i],i});
        if (it3 != sz.begin()) pq.push({abs(z[i]-(*prev(it3)).fi),{i,(*prev(it3)).se}});
        it3++;
        if (it3 != sz.end()) pq.push({abs(z[i]-(*it3).fi),{i,(*it3).se}});
    }
    for (int i = 0; i < n; i++) par[i] = i;
    ll kq = 0, cnt = 0;
    while (!pq.empty() && cnt < n-1) {
        auto [val,uv] = pq.top(); pq.pop();
        auto [u,v] = uv;
        if (_union(u,v)) kq += val, cnt++;
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