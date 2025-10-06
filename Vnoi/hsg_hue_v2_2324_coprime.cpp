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
const string NoF = "COPRIME";
    
void subtask1() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    //Tien xu ly bang "coprime"
    vector<vector<char>> cop(n,vector<char>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cop[i][j] = cop[j][i] = (gcd(a[i],a[j]) == 1);
        }
    }
    int best = 0;
    const int ALL = 1 << n;
    for (int mask = 1; mask < ALL; ++mask) {
        int cnt = __builtin_popcountll(mask);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                for (int j = i+1; j < n; ++j) {
                    if (mask >> j & 1) {
                        if (!cop[i][j]) {
                            ok = false;
                            break;
                        }
                    }
                }
            } 
        }
        if (ok) best = cnt;
    }
    cout << best << endl;
}

int main() {
    // freopen((NoF + ".in").c_str(), "r", stdin);
    // freopen((NoF + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        subtask1();
    }
}