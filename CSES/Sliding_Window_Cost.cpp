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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    multiset<int> ms1, ms2;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        auto it1 = ms1.ub(a[i]), it2 = ms2.lb(a[i]);
        if (it1 == ms1.end()) {
            if (it2 == ms2.begin()) {
                if (sz(ms1) > sz(ms2)) {ms2.insert(a[i]); sum2 += a[i];}
                else {ms1.insert(a[i]); sum1 += a[i];}
            } else {
                if (sz(ms1) == sz(ms2)) {
                    ms1.insert(*ms2.begin());
                    sum1 += *ms2.begin();
                    sum2 -= *ms2.begin();
                    ms2.erase(ms2.begin());
                    ms2.insert(a[i]);
                    sum2 += a[i];
                }
                else {ms2.insert(a[i]); sum2 += a[i];}
            }
        } else {
            if (sz(ms1) == sz(ms2)) {ms1.insert(a[i]); sum1 += a[i];}
            else {
                ms2.insert(*ms1.rbegin());
                sum2 += *ms1.rbegin();
                sum1 -= *ms1.rbegin();
                ms1.erase(prev(ms1.end()));
                ms1.insert(a[i]);
                sum1 += a[i];
            }
        }
        if (i >= k) {
            auto rit1 = ms1.lb(a[i-k]), rit2 = ms2.lb(a[i-k]);
            if (rit1 != ms1.end()) {
                if (sz(ms1) > sz(ms2)) {ms1.erase(rit1); sum1 -= a[i-k];}
                else {
                    ms1.erase(rit1);
                    sum1 -= a[i-k];
                    ms1.insert(*ms2.begin());
                    sum1 += *ms2.begin();
                    sum2 -= *ms2.begin()
;                    ms2.erase(ms2.begin());
                }
            } else {
                if (sz(ms1) == sz(ms2)) {ms2.erase(rit2); sum2 -= a[i-k];}
                else {
                    ms2.erase(rit2);
                    sum2 -= a[i-k];
                    sum1 -= *ms1.rbegin();
                    sum2 += *ms1.rbegin();
                    ms2.insert(*ms1.rbegin());
                    ms1.erase(prev(ms1.end()));
                }
            }
        }
        if (i >= k-1) {
            ll nub = *ms1.rbegin();
            cout << nub*sz(ms1)-sum1 + sum2 - nub*sz(ms2) << " ";
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