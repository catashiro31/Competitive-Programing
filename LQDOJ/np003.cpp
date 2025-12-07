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
	int l = 0, r = 1e6;
	while (l <= r) {
		int m = (l+r)/2;
		int val = m*m*m;
		if (val == n) {
			cout << "YES" << endl;
			return; 
		} else if (val > n) r = m-1;
		else l = m+1;
	}
	cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
