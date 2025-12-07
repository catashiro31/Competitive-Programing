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
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	if (m == 1) {
		cout << 0;
		return;
	}
	sort(a.rbegin(),a.rend());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum - i >= m) {
			cout << i+1;
			return;
		}
	}
	cout << -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
