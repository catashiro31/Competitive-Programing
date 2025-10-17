#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n, max_weight; cin >> n >> max_weight;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<pair<int,int>> dp((1<<n), {INT_MAX,INT_MAX});
	dp[0] = {1,0};
	for (int mask = 1; mask < (1<<n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((mask & (1<<i)) == 0) continue;
			int prv = mask ^ (1<<i);
			int num_rides = dp[prv].first, weight = dp[prv].second;
			if (weight + a[i] > max_weight) {
				dp[mask] = min(dp[mask],{num_rides+1,a[i]});
			} else {
				dp[mask] = min(dp[mask],{num_rides,weight+a[i]});
			}
		}
	}
	cout << dp[(1<<n)-1].first;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
