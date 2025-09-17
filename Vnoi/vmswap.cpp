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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int inv = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) inv += (a[i] > a[j]);
    }
    vector<vector<int>> h(n,vector<int>(n,0)), l(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            h[i][j] = h[i][j-1] + (a[i] < a[j]);
            l[i][j] = l[i][j-1] + (a[j] < a[i]);
        }
    }
    int best = inv;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            best = min(best, inv + (h[i][j-1]-h[i][i]) + (l[j][j-1]-l[j][i]) - (l[i][j-1]-l[i][i]) - (h[j][j-1]-h[j][i])-(a[i]>a[j])+(a[i]<a[j]));       
        }
    }
    cout << best << endl;
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