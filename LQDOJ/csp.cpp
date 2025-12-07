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
	sort(all(a));
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int p = upper_bound(all(a),m-a[i]) - a.begin() - 1;
		kq += min(i-1,p)+1;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
