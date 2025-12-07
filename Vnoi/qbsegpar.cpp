#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 15005

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	vector<int> tmp = prefix;
	sort(all(tmp));
	tmp.erase(unique(all(tmp)), tmp.end());
	auto rank=[&](int val) {
		return lower_bound(all(tmp),val) - tmp.begin();	
	};
	auto update1=[](vector<int> &BIT, int x, int val) {
		for (; x > 0; x -= x & (-x)) BIT[x] = min(BIT[x],val);
	};
	auto query1=[](const vector<int> &BIT, int x) {
		int res = INT_MAX;
		for (; x < BIT.size(); x += x & (-x)) res = min(res, BIT[x]);
		return res;
	};
	auto update2=[](vector<int> &BIT, int x, int val) {
		for (; x > 0; x -= x & (-x)) BIT[x] = max(BIT[x],val);
	};
	auto query2=[](const vector<int> &BIT, int x) {
		int res = INT_MIN;
		for (; x < BIT.size(); x += x & (-x)) res = max(res, BIT[x]);
		return res;
	};
	int l = -1e10, r = 1e10, kq = -1;
	while(l <= r) {
		int m = (l+r)>>1;
		bool ok = false;
		int f0 = INT_MAX, f1 = INT_MIN;
		vector<int> BIT1(n+5, LLONG_MAX), BIT2(n+5, LLONG_MIN);
		update1(BIT1,rank(0)+1,0), update2(BIT2,rank(0)+1,0);
		vector<int> dp1(n+1,0), dp2(n+1,0);
		for (int i = 1; i <= n; i++) {
			int rk = rank(prefix[i]-m) + 1;
			dp1[i] = query1(BIT1,rk) + 1;
			dp2[i] = query2(BIT2,rk) + 1;
			update1(BIT1,rank(prefix[i])+1,dp1[i]);
			update2(BIT2,rank(prefix[i])+1,dp2[i]);
		}
		if (dp1[n] <= k && k <= dp2[n]) ok = true;
		if (ok) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
