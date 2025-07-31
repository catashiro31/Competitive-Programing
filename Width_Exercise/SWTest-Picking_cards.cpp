#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const string NoF = "Name_of_File";

void solve() {
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        int n, K;
        cin >> n >> K;
        vector<int> card(n);
        for (int &x : card) cin >> x;

        map<ll, int> sl;
        sl[0] = 1;
        int m = (n - 1) / 2;
        
        for (int mask = 1; mask < (1 << (m + 1)); mask++) {
            ll tmp = 0;
            for (int i = 0; i <= m; i++) {
                if (mask & (1 << i)) tmp += card[i];
            }
            sl[tmp]++;
        }
        
        ll kq = 0;
        
        for (int mask = 1; mask < (1 << (n - m - 1)); mask++) {
            ll tmp = 0;
            for (int i = 0; i < (n - m - 1); i++) {  
                if (mask & (1 << i)) tmp += card[m + 1 + i]; 
            }
            kq += sl[K - tmp];
        }
        
        cout << "#" << q << " " << kq << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
//  freopen((NoF + ".in").c_str(),"r",stdin);
//  freopen((NoF + ".out").c_str(),"w",stdout);
    
    solve();
}
