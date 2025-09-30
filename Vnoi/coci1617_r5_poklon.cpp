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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<pair<pair<int,int>,int>> query(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        query[i] = {{l, r}, i};
    }

    int s = max(1, (int)sqrt(n));
    sort(all(query), [&](auto &A, auto &B){
        int bA = A.fi.fi / s, bB = B.fi.fi / s;
        if (bA != bB) return bA < bB;

        if (bA & 1) return A.fi.se > B.fi.se;
        return A.fi.se < B.fi.se;
    });

    vector<int> tmp = a;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    auto rankv = [&](int v){
        return int(lower_bound(all(tmp), v) - tmp.begin());
    };
    for (int i = 0; i < n; i++) a[i] = rankv(a[i]);

    vector<int> cnt(sz(tmp) + 5, 0), kq(q);
    int val = 0;

    auto add = [&](int idx){
        int x = a[idx];
        if (cnt[x] == 2) --val;
        ++cnt[x];
        if (cnt[x] == 2) ++val;
    };
    auto remove_ = [&](int idx){
        int x = a[idx];
        if (cnt[x] == 2) --val;
        --cnt[x];
        if (cnt[x] == 2) ++val;
    };

    int cl = 0, cr = -1;

    for (auto [lr, id] : query) {
        int l = lr.fi, r = lr.se;

        while (cr < r) add(++cr);
        while (cr > r) remove_(cr--);
        while (cl < l) remove_(cl++);
        while (cl > l) add(--cl);

        kq[id] = val;
    }

    for (int x : kq) cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
}
