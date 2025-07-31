#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, K; cin >> n >> K;
	int arr[n+1];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	vector<vector<long>> dp(n+1,vector<long>(K+1,0));
	int m = 0; long s = 0;
	for (int i = 1; i <= n; i++) {
		m = max(m,arr[i]);
		s += arr[i];
		dp[i][0] = m*i-s;
		for (int k = 1; k <= K; k++) {
			int cmax = arr[i];
			long sum = arr[i];
			dp[i][k] = dp[i][k-1];
			for (int j = i-1; j >= k; j--) {
				dp[i][k] = min(dp[i][k],dp[j][k-1] + cmax*(i-j)-sum);
				cmax = max(cmax,arr[j]);
				sum += arr[j];
			}
		}
	}
	cout << dp[n][K];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	solve();
}
