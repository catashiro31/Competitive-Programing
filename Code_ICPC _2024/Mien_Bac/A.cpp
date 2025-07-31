//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int n, D, H; cin >> n >> D >> H;
//	int h[n];
//	for (int &x : h) cin >> x;
//	queue<pair<int,long>> q;
//	q.push({0,h[0]});
//	long kq = LONG_MAX;
//	while (!q.empty()) {
//		int pos = q.front().first;
//		long sum = q.front().second;
//		int ht = h[pos];
//		q.pop();
//		for (int i = pos+1; i <= min(pos+D,n-1); i++) {
//			if (abs(h[i]-ht) > H) continue;
//			if (q.front().first != pos && h[i] < h[q.front().first] && i > q.front().first) q.pop();
//			q.push({i,sum+h[i]});
//			if (i == n-1) kq = min(kq,sum+h[i]);
//		}
//	}
//	if (kq != LONG_MAX) cout << kq;
//	else cout << -1;
//}
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, D, H; cin >> n >> D >> H;
	vector<int> h(n);
	for (int &x : h) cin >> x;
	vector<long> dp(n,LONG_MAX);
	dp[0] = h[0];
	for (int i = 1; i < n; i++) {
		for (int j = max(0,i-D); j < i; j++) {
			if (abs(h[i]-h[j]) <= H && dp[j] != LONG_MAX) {
				dp[i] = min(dp[i],dp[j]+h[i]);
			}
		}
	}
	if (dp[n-1] != LONG_MAX) cout << dp[n-1];
	else cout << -1;
	cerr << "\nTime elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
