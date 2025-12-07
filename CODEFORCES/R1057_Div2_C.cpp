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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	map<int,int> sl;
	for (int i = 0; i < n; i++) sl[a[i]]++;
	vector<int> odd, even;
	int base = 0;
	for (auto [u,x] : sl) {
		base = base + u * (x/2);
		if (x % 2 == 1) odd.psb(u);
		else even.psb(u);
	}
	if (base == 0) {
		cout << 0 << endl;
		return;
	}
	int kq = 0;
	for (int x : odd) {
		if (x < base * 2) kq = max(kq, base*2 + x);
	}
	sort(all(odd));
	for (int i = 1; i < odd.size(); i++) {
		if (odd[i-1] + 2*base > odd[i]) kq = max(kq,odd[i-1]+odd[i]+2*base);
	}
	for (int x : even) {
		if (base - x > 0) kq = max(kq,base*2);
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
