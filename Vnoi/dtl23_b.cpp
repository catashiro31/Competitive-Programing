#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
void solve() {
	vector<int> snt;
	vector<bool> sangnt(1e6+1,true);
	sangnt[0] = false, sangnt[1] = false;
	for (ll i = 2; i <= 1e6; i++) {
		if (!sangnt[i]) continue;
		snt.psb(i);
		for (ll j = i*i; j <= 1e6; j += i) sangnt[j] = false;
	}
	vector<bool> is_semi_prime(1e6+1,false);
	for (int i = 0; i < sz(snt); i++) {
		for (int j = i+1; j < sz(snt); j++) {
			ll val = 1LL*snt[i]*snt[j];
			if (val > 1e6) break;
			is_semi_prime[val] = true;
		}
	}
	vector<int> cnt(1e6+1,0);
	for (int i = 2; i <= 1e6; i++) {
		cnt[i] = cnt[i-1] + is_semi_prime[i];
	}
	int n; cin >> n;
	while (n--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x1 = a, x2 = c, y1 = b, y2 =d;
		int sl_x = upper_bound(all(snt),x2) - lower_bound(all(snt),x1);
		int sl_y = upper_bound(all(snt),y2) - lower_bound(all(snt),y1);
		ll res = 1LL*sl_x * sl_y;
		if (min(x2,y2)-max(x1,y1) >= 0) res -= upper_bound(all(snt),min(x2,y2)) - lower_bound(all(snt),max(x1,y1));
		if (x1 <= 1) {
			int l = y1, r = y2;
			res += cnt[r] - (l-1 < 0 ? 0 : cnt[l-1]);
		} 
		if (y1 <= 1) {
			int l = x1, r = x2;
			res += cnt[r] - (l-1 < 0 ? 0 : cnt[l-1]);
		}
		cout << res<< endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
