#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t, a, b; cin >> t >> a >> b;
	vector<bool> dp(t+1,false);
	dp[0] = true;
	for (int i = 0; i <= t; i++) {
		if (i - a >= 0 && dp[i-a]) dp[i] = true;
		else if (i-b >= 0 && dp[i-b]) dp[i] = true;  
	}
	for (int i = 0; i <= t; i++) if (dp[i]) dp[i/2] = true;
	for (int i = 0; i <= t; i++) {
		if (i - a >= 0 && dp[i-a]) dp[i] = true;
		else if (i-b >= 0 && dp[i-b]) dp[i] = true;  
	}
	while (!dp[t]) t--;
	cout << t;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);
	solve();
}
