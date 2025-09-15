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
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> mp;
    mp['L'] = 0, mp['I'] = 1, mp['T'] = 2;
    vector<int> cnt(3,0);
    for (int i = 0; i < n; i++) cnt[mp[s[i]]]++;
    int a = *max_element(all(cnt));
    int b = cnt[0] + cnt[1] + cnt[2];
    if (a*3 - b > 2*n || cnt[0] == b || cnt[1] == b || cnt[2] == b) cout << -1 << endl;
    else if (cnt[0] == cnt[1] && cnt[0] == cnt[2]) cout << 0 << endl;
    else {
        cout << a*3-b << endl;
        int p;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                p = i;
                break;
            }
        }
        for (int i = 0; i < a-cnt[mp[s[p]]]; i++) cout << p << endl;
        for (int i = 0; i < a*3-b-(a-cnt[mp[s[p]]]); i++) cout << p+i << endl;
    } 
}
    
int main() {
#ifndef ONLINE_JUDGE
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}