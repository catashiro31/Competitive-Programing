#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<int> sl(26,0);
	for (char x : s) sl[x-'a']++;
	for (char x : t) sl[x-'a']--;
	for (int i = 0; i < 26; i++) {
		if (sl[i] != 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}