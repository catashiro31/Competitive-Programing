#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> dp(n+1,INT_MAX);
	dp[n] = 0;
	for (int i = n; i >= 1; i--) {
		if (dp[i] != INT_MAX) {
			int k = i;
			while (k) {
				dp[i-k%10] = min(dp[i-k%10],dp[i] + 1);
				k/= 10;
			}
		}
	}
	cout << dp[0];
}
