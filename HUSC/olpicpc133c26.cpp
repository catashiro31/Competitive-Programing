#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[a[i]] = i;

    auto check_ok = [&](int i) {
        int next_i = (i + 1) % n;
        int target = (a[i] % n) + 1;
        return a[next_i] == target;
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (check_ok(i)) cnt++;
    }

    while (q--) {
        int x, y; cin >> x >> y;
        int u = pos[x], v = pos[y];

        set<int> idx_to_check;
        
        idx_to_check.insert(u);
        idx_to_check.insert((u - 1 + n) % n);
        
        idx_to_check.insert(v);
        idx_to_check.insert((v - 1 + n) % n);

        for (int i : idx_to_check) {
            if (check_ok(i)) cnt--;
        }
        
        swap(a[u], a[v]);
        pos[x] = v, pos[y] = u;

        for (int i : idx_to_check) {
            if (check_ok(i)) cnt++;
        }

        if (cnt == n) cout << "DA" << endl;
        else cout << "NE" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) solve();
}