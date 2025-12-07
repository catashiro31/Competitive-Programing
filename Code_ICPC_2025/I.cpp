#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, k, x; cin >> n >> k >> x;
    vector<vector<int>> dp(61, vector<int>(61,0));
    dp[60][0] = 1;  
    for(int i=60; i>0; i--) {
        int bitx= (x>>(i-1))&1;
        int bitn= (n>>(i-1))&1;
        for(int j=0; j<=k; j++) {
            if(dp[i][j]==0) continue;
            if(bitx == 1) {
                if(j<k && bitn==1) {
                    dp[i-1][j+1]= (dp[i-1][j+1] + dp[i][j]) % MOD;
                }
            }
            else {
                dp[i-1][j]= (dp[i-1][j] + dp[i][j]) % MOD;
                if(j<k && bitn==1) {
                    dp[i-1][j+1]= (dp[i-1][j+1] + dp[i][j]) % MOD;
                }
            }
        }
    }
    int res= 0;
    for(int j= 0; j<=k; j++) {
        res= (res + dp[0][j]) % MOD;
    }
    cout << res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
