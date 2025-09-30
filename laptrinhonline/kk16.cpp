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
    int n, q; cin >> n >> q;
    vector<int> h(n);
    for (int &x : h) cin >> x;
    vector<int> left(n), right(n);
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        while(!st.empty() && h[i] >= h[st.top()]) st.pop();
        if (st.empty()) right[i] = i;
        else right[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while(!st.empty() && h[i] >= h[st.top()]) st.pop();
        if (st.empty()) left[i] = i;
        else left[i] = st.top();
        st.push(i);
    }
    vector<vector<int>> blift(n,vector<int>((int)log2(n)+2));
    for (int i = 0; i < n; i++) {
        if (right[i] == i && left[i] == i) blift[i][0] = i;
        else if (right[i] == i) blift[i][0] = left[i];
        else if (left[i] == i) blift[i][0] = right[i];
        else {
            if (abs(i-right[i]) < abs(i-left[i])) blift[i][0] = right[i];
            else if (abs(i-right[i]) > abs(i-left[i])) blift[i][0] = left[i];
            else {
                if (h[left[i]] < h[right[i]]) blift[i][0] = right[i];
                else if (h[left[i]] > h[right[i]]) blift[i][0] = left[i];
            }
        }
    }
    for (int k = 1; k < (int)log2(n)+2; k++) {
        for (int i = 0; i < n; i++) {
            blift[i][k] = blift[blift[i][k-1]][k-1];
        }
    }
    while (q--) {
        int p, k; cin >> p >> k;
        --p;
        int i = 0;
        while(k) {
            if (k&1) p = blift[p][i];
            k >>= 1;
            ++i;
        }
        cout << h[p] << endl;
    }
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