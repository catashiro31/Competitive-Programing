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
int dp[205][205][205];

int solveDP(int l, int r, int k, const vector<pair<int,int>> &arr) {
    if (l > r) return 0;
    int &res = dp[l][r][k];
    if (res != -1) return res;
    
    if (l == r) return res = (arr[r].se + k) * (arr[r].se + k);

    res = solveDP(l,r-1,0,arr) + (arr[r].se + k) * (arr[r].se + k);

    for (int i = l; i < r; ++i) {
        if (arr[i].fi == arr[r].fi) {
            res = max(res, solveDP(l,i,k+arr[r].se,arr) + solveDP(i+1,r-1,0,arr));
        }
    }
    return res;
}
void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int cur = str[0]-'0', cnt = 1;
    vector<pair<int,int>> arr;
    for (int i = 1; i < n; i++) {
        if (cur != str[i]-'0') {
            arr.psb({cur,cnt});
            cur = str[i]-'0';
            cnt = 1;
        } else cnt++; 
    }
    arr.psb({cur,cnt});
    int m = sz(arr);
    memset(dp,-1,sizeof(dp));
    cout << solveDP(0, m-1, 0, arr); 
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