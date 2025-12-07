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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<pair<int,int>> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i].fi;
		b[i].se = i;
	}
	vector<pair<pair<int,int>,int>> xet(n);
	for (int i = 0; i < n; i++) xet[i].se = i+1;
	for (int i = 0; i < n; i++) xet[a[i]-1].fi.fi = n-i;
	sort(all(b),[](auto &a, auto &b){
		return a.fi > b.fi;
	});
	for (int i = 0; i < n; i++) xet[b[i].se].fi.se = n-i;
	sort(all(xet),[](auto &a, auto &b) {
		if (a.fi.fi+a.fi.se != b.fi.fi + b.fi.se) return a.fi.fi + a.fi.se > b.fi.fi + b.fi.se;
		return a.fi.se > b.fi.se;
	});
	for (int i = 0; i < n; i++) {
		string label = to_string(xet[i].se);
		if (xet[i].se < 10) label = "0" + label; 
		cout << i+1 << ". Kod" << label << " (" << xet[i].fi.fi + xet[i].fi.se << ")\n"; 
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
