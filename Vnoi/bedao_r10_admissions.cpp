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
    
void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<pair<int,int>> toan, tin, tt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        toan.psb({x,i});
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tin.psb({x,i});
    }
    for (int i = 0; i < n; i++) tt.psb({toan[i].fi+tin[i].fi,i});
    sort(all(toan),[](auto a, auto b) {
        if (a.fi > b.fi) return true;
        else if (a.fi < b.fi) return false;
        return a.se < b.se;
    });
    sort(all(tin),[](auto a, auto b) {
        if (a.fi > b.fi) return true;
        else if (a.fi < b.fi) return false;
        return a.se < b.se;
    });
    sort(all(tt),[](auto a, auto b) {
        if (a.fi > b.fi) return true;
        else if (a.fi < b.fi) return false;
        return a.se < b.se;
    });
    vector<bool> check(n,false);
    set<int> kq;
    int i = 0;
    while (a) {
        if (check[toan[i].se]) i++;
        else {
            kq.insert(toan[i].se);
            check[toan[i].se] = true;
            i++; a--;
        } 
    } 
    i = 0;
    while (b) {
        if (check[tin[i].se]) i++;
        else {
            kq.insert(tin[i].se);
            check[tin[i].se] = true;
            i++; b--;
        }
    }
    i = 0;
    while (c) {
        if (check[tt[i].se]) i++;
        else {
            kq.insert(tt[i].se);
            check[tt[i].se] = true;
            i++; c--;
        }
    }
    for (int x : kq) cout << x+1 << endl;
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