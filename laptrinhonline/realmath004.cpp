#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<long> arr(n);
	for (long &vl : arr) cin >> vl;
	vector<long> dp(m+1,0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= arr[i]; j--) {
			dp[j] = (dp[j]+dp[j-arr[i]])%mod;
		}
	}
	if (m != 0) {
		cout << dp[m];
		return 0;
	} else cout << dp[m]-1;
}