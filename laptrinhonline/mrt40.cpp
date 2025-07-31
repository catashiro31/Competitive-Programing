#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> dp(n+1,-1);
	dp[0] = 0;
	int c[] = {6,9,20};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= n-c[i]; j++) if (dp[j] != -1) dp[j+c[i]] = max(dp[j+c[i]],dp[j]+1);
	}
	cout << dp[n];
}
