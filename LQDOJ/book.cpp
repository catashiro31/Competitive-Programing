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
	sort(a.rbegin(), a.rend());
	int sum = 0, sub = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
		if (i % 3 == 2) sub+= a[i];
	}
	cout << sum -sub;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
