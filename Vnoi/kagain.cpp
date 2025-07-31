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
#define endl '\n'
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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = 0;

    stack<int> st;
    int maxArea = 0, u = 1, v = 1;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int height = a[st.top()]; st.pop();
            int left = st.empty() ? -1 : st.top();
            int width = i - left - 1;
            int area = height * width;
            
            if (area > maxArea) {
                maxArea = area;
                u = left + 2;
                v = i;
            } else if (area == maxArea && u > left+2) u = left+2, v = i;
        }
        st.push(i);
    }
    cout << maxArea << " " << u << " " << v << endl;
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
