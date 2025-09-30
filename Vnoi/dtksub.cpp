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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> hashT(n+1,0), p(n+1,1);
    for (int i = 1; i <= n; i++) {
        hashT[i] = (hashT[i-1] * 31 + s[i-1]-'a'+1) % MOD;
        p[i] = (p[i-1] * 31) % MOD;
    }
    auto get_hash = [&](int l, int r) {
        return ((hashT[r] - hashT[l] * p[r-l]) % MOD + MOD) % MOD;
    };
    int l = 1, r = n;
    int kq = l;
    while (l <= r) {
        int m = (r+l) >> 1;
        unordered_map<ll,int> sl;
        bool c = false;
        for (int i = 0; i+m <= n; i++) {
            ll hash = get_hash(i,i+m);
            sl[hash]++;
            if (sl[hash] >= k) {
                c = true;
                break;
            }
        }
        if (c) kq = m, l = m+1;
        else r = m-1; 
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