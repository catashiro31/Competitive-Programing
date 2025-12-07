#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int a, b; cin >> a >> b;
	int c = a^b;
	if (c == 0) {
		cout << 0 << endl;
		return;
	}
	int lc = log2(c), la = log2(a);
	if (lc <= la) {
		vector<int> kq;
		for (int k = la; k >= 0; k--) {
			if ((c>>k)&1) kq.psb(1<<k);
		}
		cout << kq.size() << endl;
		sort(all(kq));
		for (int x : kq) cout << x << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
