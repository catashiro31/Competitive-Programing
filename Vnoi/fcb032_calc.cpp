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
	int a1, a2, a3;
	while (cin >> a1) {
		cin >> a2 >> a3;
		if (a1 + a2 - a3 == 0) cout << "yes" << endl;
		else if (a2 + a3 - a1 == 0) cout << "yes" << endl;
		else if (a1 + a3 - a2 == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
