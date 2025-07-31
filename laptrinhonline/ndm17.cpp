#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int n, m, h; cin >> n >> m >> h;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] ={x,i};
    }
    sort(all(a));
    for (int i = 0; i <= n-m; i++) {
        if (a[i+m-1].fi - a[i].fi <= h) cout << a[i].se+1 << endl;
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