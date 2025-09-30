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

void update(vector<int> &BIT, int id) {
    for (; id < sz(BIT); id+=id&(-id)) BIT[id]++;
} 

ll get(const vector<int> &BIT, int id) {
    ll res = 0;
    for (; id > 0; id-=id&(-id)) res += BIT[id];
    return res; 
}

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<ll> tmp;
    ll sum = 0;
    tmp.psb(sum);
    for (int i = 0; i < n; i++) {
        sum += a[i];
        tmp.psb(sum);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),tmp.end());
    auto rank = [&](ll v) {
        return int(lb(all(tmp),v)-tmp.begin())+1;
    };
    ll l = -4e18, r = 4e18;
    ll kq = LLONG_MIN;
    while (l <= r) {
        ll m = (r+l)>>1;
        ll prefix = 0;
        ll cnt = 0;
        vector<int> BIT(sz(tmp)+5,0);
        update(BIT,rank(0));
        for (int i = 0; i < n; i++) {
            prefix += a[i];
            cnt += get(BIT,ub(all(tmp),prefix-m)-tmp.begin());
            update(BIT,rank(prefix));
        }
        if (cnt >= k) {
            if (cnt == k) kq = max(kq,m);
            l = m+1;
        } else r = m-1;
    }
    cout << kq;
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