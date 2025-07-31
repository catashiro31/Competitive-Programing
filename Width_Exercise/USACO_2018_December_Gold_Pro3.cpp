#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	int arr[n+1];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	vector<int> dp(n+1,0);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + arr[i];
		int cmax = arr[i];
		for (int j = 1; j <= min(i,k); j++) {
			dp[i] = max(dp[i],dp[i-j]+cmax*j);
			cmax = max(cmax,arr[i-j]);
		}
	}
	cout << dp[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	solve();
}
