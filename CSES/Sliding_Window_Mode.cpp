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
    vector<int> b = a;
    sort(all(b));
    map<int,int> to1, to2;
    for (int i = 0; i < n; i++) to1[b[i]] = i+1, to2[i+1]=b[i];
    set<pair<int,int>> s;
    vector<int> mode(n,0);
    for (int i = 0; i < n; i++) {
        int pj = to1[a[i]], sl = mode[pj];
        auto it = s.find({sl,pj});
        if (it == s.end()) {
            s.insert({sl+1,pj});
            mode[pj] = sl+1;
        } else {
            s.erase(it);
            s.insert({sl+1,pj});
            mode[pj] = sl+1;
        }
        if (i >= k) {
            auto eit = s.find({mode[to1[a[i-k]]],to1[a[i-k]]});
            if ((*eit).se == 1) {s.erase(eit); mode[to1[a[i-k]]]--;}
            else {
                int tmp = mode[to1[a[i-k]]];
                s.erase(eit);
                s.insert({tmp-1,to1[a[i-k]]});
                mode[to1[a[i-k]]]--;
            }
        }
        if (i >= k-1) {
            auto eit = s.lb({(*s.rbegin()).fi,INT_MIN});
            cout << to2[(*eit).se] << " ";
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