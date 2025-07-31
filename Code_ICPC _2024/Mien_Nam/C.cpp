#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1), a(n), b(n);
    
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[b[i] - 1] = i;

    vector<bool> vis(n, false);
    int res = 0;
    int min_global = *min_element(w.begin() + 1, w.end());

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int cost = 0, m = MOD, len = 0;
        int x = i;

        while (!vis[x]) {
            vis[x] = true;
            int val = a[x] - 1;
            cost += w[a[x]];
            m = min(m, w[a[x]]);
            len++;
            x = pos[val];
        }
        int tmp1 = cost + (len - 2) * m;
        
        int tmp2 = cost + m + (len + 1) * min_global;

        res += min(tmp1, tmp2);
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}