#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int h[n];
	for (int &x : h) cin >> x;
	int dp[n];      
	dp[0] = 0; dp[1] = abs(h[1]-h[0]);
	for(int i = 2; i < n; i++) {
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout << dp[n-1];
	return 0;
}
