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
int T[MAXN][20];
int getmin(int l, int r) {
    int m = log2(r-l+1);
    return min(T[l][m],T[r-(1<<m)+1][m]);
}
void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> prefix(n+1,0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1];
        if (s[i-1] == '(') prefix[i]++;
        else prefix[i]--;
    }
    // for (int i = 0;  i <= n; i++) cout << prefix[i] << " ";
    vector<set<int>> value(2e6);
    int tmp = 1e6;
    for (int i = 0; i <= n; i++) value[prefix[i]+tmp].insert(i);
    
    for (int i = 0; i <= n; i++) T[i][0] = prefix[i];
    for (int i = 1; i <= log2(n+1); i++) {
        for (int j = 0; j + (1<<i)-1 <= n; j++) T[j][i] = min(T[j][i-1],T[j+(1<<(i-1))][i-1]);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int d = getmin(l-1,r);
        auto lit = value[d+tmp].ub(l-1);
        if (lit == value[d+tmp].begin()) {
            cout << "-1\n";
            continue;
        }
        auto rit = value[d+tmp].lb(r);
        if (rit == value[d+tmp].end()) {
            cout << "-1\n";
            continue;
        }
        cout << (*(--lit))+1 << " " << *rit << endl;
    }
}
    
int main() {
#ifndef ONLINE_JUDGE
    freopen((NoF + ".in").c_str(), "r", stdin);
    freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}