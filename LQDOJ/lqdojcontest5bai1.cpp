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
	int a, b; cin >> a >> b;
	if (a == 1 || a == 15) cout << "den" << endl;
	else if (a == 2 || a == 14) {
		if (b == 1 || b == 15) cout << "den" << endl;
		else cout << "trang" << endl;
	} else if (a == 3 || a == 13) {
		if (b == 2 || b == 14) cout << "trang" << endl;
		else cout << "den" << endl;
	} else if (a == 4 || a == 12) {
		if (b == 1 || b == 3 || b == 13 || b == 15) cout << "den" << endl;
		else cout << "trang" << endl;
	} else if (a == 5 || a == 11) {
		if (b == 2 || b == 4) cout << "trang" << endl;
		else cout << "den" << endl;
	} else if (a == 6 || a == 10) {
		if (b == 1 || b == 3 || b == 5 || b == 15 || b == 13 || b == 11) cout << "den" << endl;
		else cout << "trang" << endl;
	} else if (a == 7 || a == 9) {
		if (b == 2 || b == 4 || b == 6 || b == 14 || b == 12 || b == 10) cout << "trang" << endl;
		else cout << "den" << endl;
	} else {
		if (b == 2 || b == 4 || b == 6 || b == 8 || b == 10 || b == 12 || b == 14) cout << "trang" << endl;
		else cout << "den" << endl; 
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
