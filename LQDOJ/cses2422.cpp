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
	int p = n*n/2+1;
	int l = 1, r = 1e14, kq = 0;
	while (l <= r) {
		int m = (l+r)/2;
		int val = 0;
		for (int i = 1; i <= n; i++) {
			val += 2*max(0LL,min(n,m/i)-i);
			if (i*i <= m) val++;
		}
//		cout << m << " " << val << endl;
		if (val >= p) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
