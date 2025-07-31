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
    ll n, l, u; cin >> n >> l >> u;
    vector<ll> arr(n);
    for (ll &x : arr) cin >> x;

    ll total = n * (n + 1) / 2;
    ll ans = total;

    // Loại bỏ đoạn có < l phần tử phân biệt
    if (l > 1) {
        unordered_map<ll, int> freq;
        int i = 0, j = 0, cnt = 0;
        while (j < n) {
            if (++freq[arr[j]] == 1) cnt++;
            while (i < j && cnt >= l) {
                if (--freq[arr[i]] == 0) cnt--;
                i++;
            }
            ans -= (j - i + 1);
            j++;
        }
    }

    // Loại bỏ đoạn có > u phần tử phân biệt
    if (u < n) {
        unordered_map<ll, int> freq;
        int i = 0, j = 0, cnt = 0;
        while (j < n) {
            if (++freq[arr[j]] == 1) cnt++;
            while (i < j && cnt > u) {
                if (--freq[arr[i]] == 0) cnt--;
                i++;
            }
            if (cnt == u) ans -= i;
            j++;
        }
    }

    cout << ans << endl;
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