#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	vector<int> c(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> t[i];
		--c[i];
	}
	int l = 0, r=1e18, kq = 0; 
	while (l <= r) {
		int m = (l+r)>>1;
		bool check = true;
		vector<pair<int,int>> limit(n);
		for (int i = 0; i < n; i++) {
			int x = m/t[i];
			int u = max(0LL, c[i]-x);
			int v = min(n-1, c[i]+x);
			limit[i] = {u, v};
		}
		sort(all(limit));
		priority_queue<int, vector<int>, greater<int>> pq;
        int limit_idx = 0;
		for (int pos = 0; pos < n; ++pos) {
			while(limit_idx < n && limit[limit_idx].first <= pos) {
				pq.push(limit[limit_idx].second);
				limit_idx++;
			}
			if (pq.empty()) {
				check = false;
				break;
			}
			int R_min = pq.top(); pq.pop();
			if (R_min < pos) {
				check = false;
				break;
			}
		}
		if (check) {
            kq = m;
            r = m-1;
        }
		else l = m+1;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}