#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else {
                dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),(a[i-1] == b[j-1]) ? dp[i-1][j-1]+1:0);
            } 
        }
    }
    cout << dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}