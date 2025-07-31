#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vector<long> prefix_sum(n+1,0);
	for (int i = 1; i <= n; i++) {
		long x; cin >> x;
		prefix_sum[i] = prefix_sum[i-1]+x;
	}
	long long cmax = LLONG_MIN;
	long long cmin = LLONG_MAX;
	long long kq = LLONG_MIN;
	for (int i = k; i <= n-k; i++) {
		long long tmp = prefix_sum[i]-prefix_sum[i-k];
		cmin = min(cmin,tmp);
		cmax = max(cmax,tmp);
		long long diff = prefix_sum[i+k] - prefix_sum[i];
		kq = max({kq,abs(diff-cmax),abs(diff-cmin)});
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
