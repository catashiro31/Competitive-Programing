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
	string a, b; cin >> a >> b;
	vector<pair<char,int>> sla, slb;
	char c = '-';
	for (int i = 0; i < a.size(); i++) {
		if (c != a[i]) {
			sla.psb({a[i],1});
			c = a[i];
		} else sla[sla.size()-1].se++;
	}
	c = '-';
	for (int i = 0; i < b.size(); i++) {
		if (c != b[i]) {
			slb.psb({b[i],1});
			c = b[i];
		} else slb[slb.size()-1].se++;
	}
	if (sla.size() != slb.size()) cout << "NO" << endl;
	else {
		int n = sla.size();
		for (int i = 0; i < n; i++) {
			if (sla[i].fi != slb[i].fi) {
				cout << "NO" << endl;
				return;
			} else {
				if (sla[i].se*2 < slb[i].se || sla[i].se > slb[i].se) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		cout << "YES" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
