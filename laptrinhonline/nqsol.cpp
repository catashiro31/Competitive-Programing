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
    string nt; cin >> nt;
    int x; cin >> x;
    string kq[1000] = {"A0","A#0","B0","C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1"};
    for (int i = 0; i < 12; i++) {
        for (int j = 1; j <= 10; j++) {
            kq[i+j*12] = kq[i];
            kq[i+j*12][sz(kq[i+j*12])-1]+=j;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (nt == kq[i]) {
            cout << kq[i+x];
            return;
        }
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