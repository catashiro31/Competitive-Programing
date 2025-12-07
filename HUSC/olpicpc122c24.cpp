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

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> ab(n);
	for (int i = 0; i < n; i++) cin >> ab[i].fi;
	for (int i = 0; i < n; i++) cin >> ab[i].se;
	sort(all(ab),[](auto &a, auto &b){
		if (a.fi != b.fi) return a.fi < b.fi;
		return a.se > b.se;
	});
	multiset<int> mls;
	for (int i = 0; i < n; i++) {
		int val = ab[i].se;
		auto it = mls.upper_bound(val);
		if (it == mls.end()) mls.insert(val);
		else {
			mls.erase(it);
			mls.insert(val);
		}
	}
	cout << mls.size();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
