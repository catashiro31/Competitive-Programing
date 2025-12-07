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

bool pal(string s) {
	int l = 0, r = s.size()-1;
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++, r--;
	}
	return true;
}

void solve() {
	string str; cin >> str;
	int n = str.size();
	str = " " + str;
	vector<int> dp(n+1,LLONG_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i-1] == LLONG_MAX) continue;
		for (int j = n; j >= i; j--) {
			string s = str.substr(i,j-i+1);
			if (pal(s)) dp[j] = min(dp[j], dp[i-1] + 1);
		}
	}
	cout << dp[n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
