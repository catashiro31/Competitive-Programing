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
    int n; cin >> n;
    int a[4][n];
    bool hasPositive = false;
    int maxVal = INT_MIN;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0) hasPositive = true;
            maxVal = max(maxVal, a[i][j]);
        }
    }

    int prev[1<<4], cur[1<<4];
    int bitmask[8] = {0,1,2,4,8,5,9,10};

    for (int mask : bitmask) cur[mask] = INT_MIN;
    for (int mask : bitmask) {
        int tmp = INT_MIN;
        for (int i = 0; i < 4; i++) {
            if (mask&(1<<i)) {
                if (tmp == INT_MIN) tmp = a[i][0];
                else tmp += a[i][0];
            }
        }
        prev[mask] = tmp;
    }

    for (int i = 1; i < n; i++) {
        for (int mask1 : bitmask) {
            if (prev[mask1] == INT_MIN) continue;
            for (int mask2 : bitmask) {
                if ((mask1&mask2) != 0) continue;
                int Sum = 0;
                for (int j = 0; j < 4; j++) {
                    if (mask2&(1<<j)) Sum += a[j][i];
                }
                cur[mask2] = max(cur[mask2],prev[mask1]+Sum);
            }
        }
        for (int mask : bitmask) prev[mask] = cur[mask], cur[mask] = INT_MIN;
    }

    int kq = INT_MIN;
    for (int mask : bitmask) kq = max(kq,prev[mask]);

    cout << (hasPositive ? kq : maxVal);
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