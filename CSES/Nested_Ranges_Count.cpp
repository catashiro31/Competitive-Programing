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
const int MAXN = 2e5 + 5;
const string NoF = "Name_of_File";
void update(vector<int> &BIT, int x, int val) {
    for (; x < sz(BIT); x += x&(-x)) BIT[x] += val;
}

int get(const vector<int> &BIT, int x) {
    int res = 0;
    for (; x > 0; x -= x&(-x)) res += BIT[x];
    return res;
}

void solve() {
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> ranges(n);
    for (int i = 0; i < n; i++) {
        ranges[i].fi = i;
        cin >> ranges[i].se.fi >> ranges[i].se.se;
    }

    vector<int> val;
    for (int i = 0; i < n; i++) val.psb(ranges[i].se.fi), val.psb(ranges[i].se.se);
    sort(all(val));
    val.erase(unique(all(val)),val.end());
    auto rank_of = [&](int v) {
        return int(lower_bound(all(val),v) - val.begin()) + 1;
    };
    for (int i = 0; i < n; i++) ranges[i].se.fi = rank_of(ranges[i].se.fi), ranges[i].se.se = rank_of(ranges[i].se.se);

    sort(all(ranges),[&](auto &a, auto &b){
        if (a.se.fi != b.se.fi) return a.se.fi < b.se.fi;
        return a.se.se > b.se.se;
    });
    vector<int> BIT1(sz(val)+5,0), BIT2(sz(val)+5,0);
    for (int i = 0; i < n; i++) update(BIT1,ranges[i].se.se,1);
    vector<pair<int,int>> kq(n);
    for (int i = 0; i < n; i++) {
        update(BIT1,ranges[i].se.se,-1);
        kq[ranges[i].fi].fi = get(BIT1,ranges[i].se.se);
        kq[ranges[i].fi].se = i - get(BIT2,ranges[i].se.se-1);
        update(BIT2,ranges[i].se.se,1);
    }
    for (int i = 0; i < n; i++) cout << kq[i].fi << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << kq[i].se << " ";
}
    
int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}