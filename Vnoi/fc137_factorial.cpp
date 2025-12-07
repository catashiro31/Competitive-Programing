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
	string s; cin >> s;
	int n = s.length(), k; cin >> k;
	if (k == 1) cout << "YES" << endl;
	else {
		bool div2 = false, div3 = false;
		if (s[n-1] == '0' || s[n-1] == '2' || s[n-1] == '4' || s[n-1] == '6' || s[n-1] == '8') div2 = true;
		int sum = 0;
		for (int i = 0; i < n; i++) sum += s[i]-'0';
		if (sum % 3 == 0) div3 = true;
		if (k == 2) {
			if (div2) cout << "YES" << endl;
			else cout << "NO" << endl;
		} else {
			if (div2 && div3) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
