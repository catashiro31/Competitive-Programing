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
    int n; cin >> n;
    string s; cin >> s;
    int kq = 0;
    char tmp = '0';
    for (int i = 0; i < n; i++) {
        if (tmp == s[i]) kq++;
        else kq+=2, tmp = s[i];
    }
    string xau = "0" + s;
    int i = 0, j = n;
    while(i < n && !(xau[i] == '0' && xau[i+1] == '1')) i++;
    while(j > 1 && !(xau[j] == '1' && xau[j-1] == '0')) j--;
    if (j-i > 1) cout << kq - 2 << endl;
    else {
        int p0 = n-1, p1 = 0;
        while (p0 >= 0 && s[p0] != '0') p0--;
        while (p1 < n && s[p1] != '1') p1++;
        if (p1 > p0) cout << kq << endl;
        else cout << kq-1 << endl;
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