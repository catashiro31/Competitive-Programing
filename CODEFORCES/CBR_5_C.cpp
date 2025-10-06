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
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> c(n, -1);
    vector<int> st; st.reserve(n);

    int best = 0, cnt = 1;
    for (int j = 0; j < n; ++j) {
        if (s[j] == '(') {
            st.push_back(j);
        } else {
            if (st.empty()) {
                c[j] = -1;
            } else {
                int p = st.back(); st.pop_back();
                c[j] = p;

                if (p - 1 >= 0 && s[p - 1] == ')' && c[p - 1] != -1)
                    c[j] = c[p - 1];

                if (j-c[j]+1 > best ) best = j-c[j]+1, cnt = 1;
                else if (j-c[j]+1 == best) cnt++;
            }
        }
    }
    cout << best << " " << cnt;
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