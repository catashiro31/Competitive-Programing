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
map<pair<ll,ll>,int> sl;
pair<ll,ll> val = {0,0};
int x[30], y [30];
int kq = 0;
pair<ll,ll> uv;
void Try(int i, int dest,int type) {
    if (i == dest) {
        if (type) sl[val]++;
        else kq += sl[{uv.fi-val.fi,uv.se-val.se}];
        return;
    }
    Try(i+1,dest,type);
    val = {val.fi+x[i],val.se+y[i]};
    Try(i+1,dest,type);
    val = {val.fi-x[i],val.se-y[i]};
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    cin >> uv.fi >> uv.se;
    Try(0,n/2,1);
    Try(n/2,n,0);
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