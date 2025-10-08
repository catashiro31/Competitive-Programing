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
    vector<ll> pwr(n+1,1);
    for (int i = 1; i <= n; i++) pwr[i] = (pwr[i-1]*31)%MOD;
    vector<ll> hash(n+1);
    hash[0] = 0;
    for (int i = 1; i <= n; i++) hash[i] = (1LL*hash[i-1]*31+s[i-1]-'a'+1)%MOD;
    string rs = s;
    reverse(all(rs));
    vector<ll> rhash(n+1);
    rhash[0] = 0;
    for (int i = 1; i <= n; i++) rhash[i] = (1LL*rhash[i-1]*31+rs[i-1]-'a'+1)%MOD;
    auto gethash = [&](const vector<ll> &hashT, int u, int v) {
        return (hashT[v]-(hashT[u-1]*pwr[v-u+1])%MOD+MOD)%MOD;
    };
    int kq = 0;
    for (int i = 1; i <= n; i++) {
        bool odd = true, even = true;
        char codd = '-', ceven = '-';
        if (i&1) codd = s[i-1];
        else ceven = s[i-1];
        for (int j = i; j <= n; j++) {
            if (j&1) {
                if (codd == '-') codd = s[j-1];
                else {
                    if (codd != s[j-1]) odd = false;
                }
            } else {
                if (ceven == '-') ceven = s[j-1];
                else {
                    if (ceven != s[j-1]) even = false;
                }
            }
            if (!odd && !even) break;
            if (gethash(hash,i,j) != gethash(rhash,n-j+1,n-i+1)) continue;
            if (i&1 && !even) continue;
            if (i%2==0 && !odd) continue;
            kq++; 
        }
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