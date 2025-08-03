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
void xau(int d, int m, int y) {
    string dd = to_string(d), mm = to_string(m), yyyy = to_string(y);
    while (sz(dd) < 2) dd = "0"+dd;
    while (sz(mm) < 2) mm = "0"+mm;
    while (sz(yyyy) < 4) yyyy = "0"+yyyy;
    cout << dd << "/" << mm << "/" << yyyy << endl;
}
void solve() {
    int d, m, y;
    scanf("%d/%d/%d",&d,&m,&y);
    vector<bool> c(31,false);
    c[2] = true, c[3] = true, c[5] = true, c[7] = true, c[11] = true;
    c[13] = true, c[17] = true, c[19] = true, c[23] = true, c[29] = true;
    set<pair<int,int>> arr;
    for (int i = 1; i <= 12; i++) {
        if (!c[i]) continue;
        for (int j = 1; j <= 30; j++) {
            if (!c[j]) continue;
            arr.insert({i,j});
        }
    }
    arr.insert({13,2}), arr.insert({13,3}), arr.insert({13,5});
    auto it1 = arr.lb({m,d});
    auto it2 = arr.ub({m,d});
    int d1, m1, y1, d2, m2, y2;
    if (it2 == arr.end()) {
        d2 = (*arr.begin()).se;
        m2 = (*arr.begin()).fi;
        y2 = y+1;
    } else {
        d2 = (*it2).se;
        m2 = (*it2).fi;
        y2 = y;
    }
    if (it1 == arr.begin()) {
        d1 = (*arr.rend()).se;
        m2 = (*arr.rend()).fi;
        y1 = y-1;
    } else {
        it1 = prev(it1);
        d1 = (*it1).se;
        m1 = (*it1).fi;
        y1 = y;
    }
    xau(d1,m1,y1);
    xau(d2,m2,y2);
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