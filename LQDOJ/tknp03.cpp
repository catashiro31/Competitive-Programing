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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		int l = 1, r = n, kq = n+1;
		while (l <= r) {
			int m = (l+r)/2;
			if (a[m-1] >= x) kq = m, r = m-1;
			else l = m+1;
		}
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
