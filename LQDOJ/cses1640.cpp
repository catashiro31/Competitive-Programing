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
	int n, s; cin >> n >> s;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(all(a));
	int l = 0, r = n-1;
	while (l < r) {
		if (a[l].fi + a[r].fi == s) {
			cout << a[l].se+1 << " " << a[r].se+1 << endl;
			return;
		} else if (a[l].fi + a[r].fi < s) l++;
		else r--;
	} 
	cout << "IMPOSSIBLE" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
