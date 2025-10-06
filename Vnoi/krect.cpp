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
    int m, n, k; cin >> m >> n >> k;
    vector<string> nstr(m);
    for (int i = 0; i < m; i++) cin >> nstr[i];
    int prefix2D[m+1][n+1][26];
    memset(prefix2D,0,sizeof(prefix2D));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 26; k++) {
                prefix2D[i][j][k] = prefix2D[i][j-1][k] + prefix2D[i-1][j][k] - prefix2D[i-1][j-1][k];
                if (nstr[i-1][j-1]-'A' == k) prefix2D[i][j][k]++;
            }
        }
    }
    int kq = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = 0; x <= i; x++) {
                for (int y = 0; y <= j; y++) {
                    int cnt = 0;
                    for (int k = 0; k < 26; k++) {
                        int val = prefix2D[i][j][k] - prefix2D[i][y][k] - prefix2D[x][j][k] + prefix2D[x][y][k];
                        if (val > 0) cnt++;
                    }
                    if (cnt == k) kq++;
                }
            }
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