#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int &vl : arr) cin >> vl;
	vector<long> dp(n,LONG_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = max(0,i-k); j < i; j++) {
			dp[i] = min(dp[i],dp[j]+abs(arr[j]-arr[i]));
		}
	}
	cout << dp[n-1];
}
