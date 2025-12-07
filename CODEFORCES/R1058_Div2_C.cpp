#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

bool check(string s) {
	bool res = true;
	int i = 0, j = s.size()-1;
	while(i <= j) {
		if (i == j) {
			if (s[i] == '1') res = false;
		} else {
			if (s[i] != s[j]) res = false;	
		}
		i++, j--;
	}	
	return res;
}

void solve() {
	int n; cin >> n;
	if (n == 0) {
		cout << "YES" << endl;
		return;
	}
	string str = "";
	while (n) {
		if (n&1) str = "1" + str;
		else str = "0" + str;
		n/=2;
	}
	if (check(str)) {
		cout << "YES" << endl;
		return;
	}
	int m = sz(str);
	for (int i = 0; i < m; i++) {
		str = "0" + str;
		if (check(str)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
