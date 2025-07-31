#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int m , r; cin >> m >> r;
	vector<long> arr(n);
	for (long &vl : arr) {
		long x; cin >> x;
		vl = x%m;
	}
	vector<long> dp(m,0);
	dp[0] = 1;
	for (long x : arr) {
		vector<long> update(m,0);
		for (int i = 0; i < m; i++) {
			update[(1LL*i*x)%m] += dp[i];
			update[(1LL*i*x)%m] %= mod;
		}
		for (int i = 1; i < m; i++) {
			dp[i] += update[i];
			dp[i] %= mod;
		}
	}
	if (r == 0) r = m;
	cout << dp[r];
}
