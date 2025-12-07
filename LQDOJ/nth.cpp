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

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y,x%y);
}

void solve() {
	int a, b, n; cin >> a >> b >> n;
	int l = 1, r = 1e18, kq = 0;
	int val = a*b/gcd(a,b);
	while (l <= r) {
		int m = (l+r)/2;
		int tmp = m/a + m/b - m/val;
		if (tmp >= n) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
