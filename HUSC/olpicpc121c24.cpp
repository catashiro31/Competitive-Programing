#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

struct Hill {
	int x, t, s;
};

void solve() {
	int n, m; cin >> n >> m;
	vector<Hill> hills(n);
	for (int i = 0; i < n; i++) cin >> hills[i].x >> hills[i].t >> hills[i].s;
	sort(all(hills),[](auto &a, auto &b){
		return a.t > b.t;	
	});
	vector<int> dp(n,0);
	for (int i = 0; i < n; i++) {
		int cur_time = hills[i].t + hills[i].s;
		for (int j = 0; j < i; j++) {
			int dif = abs(hills[i].x - hills[j].x);
			int time = cur_time + dif;
			if (time >= hills[j].t) continue;
			dp[i] = max(dp[i], (hills[j].t - time) + dp[j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		int val = 0;
		for (int j = 0; j < n; j++) {
			int dif = abs(hills[j].x-x);
			if (dif >= hills[j].t) continue;
			val = max(val, hills[j].t - dif + dp[j]);
		}
		cout << val << " ";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
