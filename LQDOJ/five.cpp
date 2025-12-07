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
	int l = 1, r = 1e12, kq = 1;
	while (l <= r) {
		int m = (l+r)/2;
		int val = 0, nub = 5;
		while (nub <= m) {
			val += (m/nub);
			nub *= 5;
		}
		if (val >= n) kq = m, r = m-1;
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
