#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		double left = log10l(a) - log10l(b), right = log10l(c) - log10l(d);
		int l = 1, r = 1e9;
		int q = -1;
		while (l <= r) {
			int m = (l+r)>>1;
			double log_m = log10l(m);
			double u = left + log_m, v = right + log_m;
			u = powl(10.0,u), v = powl(10.0,v);
			cout << u << " " << v << endl;
			if (int(u+1) < v) q = m, r = m-1;
			else l = m+1; 
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
