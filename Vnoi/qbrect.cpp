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
    int m, n; cin >> m >> n;
    vector<vector<int>> board(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    vector<int> h(n,0), l(n), r(n);
    int kq = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) h[j]++;
            else h[j] = 0;
        }
        stack<int> st;
        for (int j = 0; j < n; j++) {
            while(!st.empty() && h[st.top()] >= h[j]) st.pop();
            if (st.empty()) l[j] = -1;
            else l[j] = st.top();
            st.push(j);
        } 
        while(!st.empty()) st.pop();
        for (int j = n-1; j >= 0; j--) {
            while(!st.empty() && h[st.top()] >= h[j]) st.pop();
            if (st.empty()) r[j] = n;
            else r[j] = st.top();
            st.push(j);
        }
        for (int j = 0; j < n; j++) kq = max(kq,(r[j]-l[j]-1)*h[j]);
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