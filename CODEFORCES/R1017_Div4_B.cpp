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
	int n, m, l, r; cin >> n >> m >> l >> r;
	int i = 0, j = 0;
	while (m--) {
		if (i-l < r-j) j++;
		else i--;
	}
	cout << i << " " << j << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
