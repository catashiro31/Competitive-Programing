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
    int m; cin >> m;
    vector<int> arr(m);
    unordered_map<int,int> c;
    for (int &x : arr) {
        cin >> x;
        c[x]++;
    }
    sort(all(arr));
    set<pair<int,int>> store;
    for (int i = 0; i < m; i++) {
        auto it = store.lb({arr[i],INT_MIN});
        if (it == store.end()) store.insert({arr[i],1});
        else {
            auto [val,cnt] = *it;
            store.erase(it), store.insert({val,cnt+1});
        }
    }
    unordered_map<int,int> umap;
    int d[3] = {1, 8, 9};
    for (auto [val,cnt] : store) {
        for (int i = 0; i < 3; i++) {
            auto it = store.lb({val+d[i],INT_MIN});
            if (it == store.end()) continue;
            if ((*it).fi == val+d[i]) umap[val] += (*it).se, umap[val+d[i]] += (*it).se;
        }
    }
    vector<int> tmp;
    for (auto [val, cnt] : umap) tmp.psb(val);
    sort(all(tmp), [&](auto &a, auto &b) {
        return umap[a] > umap[b];
    });
    int kq = 0;
    for (int x : tmp) {
        if (umap[x] <= 0) continue;
        for (int i = 0; i < 3; i++) {
            auto it1 = store.lb({x+d[i],INT_MIN});
            auto it2 = store.lb({x-d[i],INT_MIN});
            if (it1 !=store.end() && (*it1).fi == x+d[i]) umap[x+d[i]] -= c[x];
            if ((*it2).fi == x-d[i]) umap[x-d[i]] -= c[x];
        }
        kq += c[x];
    }
    cout << kq;
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