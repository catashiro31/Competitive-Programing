#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
    int n, d; cin >> n >> d;
    
    multiset<int> mls;
    vector<int> s(n);
    for (int &x : s) cin >> x;
    
    sort(all(s));
    reverse(all(s));
    
    int ans = 0; 
    
    for (int i = 0; i < n; i++) {
        auto it = mls.lower_bound(s[i]);
        
        if (it == mls.end()) {
            ans++;
            
            if (d - s[i] > 0) mls.insert(d - s[i]);
        }
        else {
            int current_space = *it;
            mls.erase(it);
            
            if (current_space - s[i] > 0) {
                mls.insert(current_space - s[i]);
            }
        }
    }
    
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) solve();
}