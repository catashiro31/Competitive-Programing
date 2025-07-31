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
    string s; cin >> s;
    int n = sz(s);
    int kq = 0;
    map<char,int> pos;
    int prefix[n+1][26];
    memset(prefix,0,sizeof(prefix));
    pos[s[0]] = 1;
    prefix[1][s[0]-'a'] = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[s[i-1]] == i-1) kq++;
        else if (pos[s[i-1]]) {
            for (int j = 0; j < 26; j++) {
                if (j == s[i-1]-'a') continue;
                if (prefix[i-1][j] - prefix[pos[s[i-1]]][j] == i-1-pos[s[i-1]]) kq++;
            }
        }
        for (int j = 0; j < 26; j++) prefix[i][j] = prefix[i-1][j];
        prefix[i][s[i-1]-'a']++;
        pos[s[i-1]] = i; 
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