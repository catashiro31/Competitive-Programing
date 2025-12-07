#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

bool pal(string s) {
	int i = 0, j = sz(s)-1;
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++, j--;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	string str; cin >> str;
	if (pal(str)) {
		cout << 0 << endl;
		return;
	}
	int kq = 0;
	for (int i = 0; i < n; i++) if (str[i] == '0') kq++;
	cout << kq << endl;
	for (int i= 0; i < n; i++) {
		if (str[i] == '0') cout << i+1 << " ";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
