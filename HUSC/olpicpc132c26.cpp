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
	vector<int> a(m);
	for (int &x : a) cin >> x;
	if (m > n) cout << "NE";
	else {
		int sl = 0;
		for (int x : a) {
			if (x/4 == 0) {
				cout << "NE";
				return;
			}
			sl += x/4;
		}
		if (sl >= n) cout << "DA";
		else cout << "NE";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
