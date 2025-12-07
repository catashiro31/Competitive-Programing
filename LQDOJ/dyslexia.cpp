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
	int n = s.size();
	int zero = 0, one = 0,kq = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '1') kq += (i+1)*zero, one += n-i;
		else kq += (i+1)*one, zero += n-i;
	}
	int i = 0;
	while (i < n) {
		int j = i;
		while (i < n && s[i] == s[j]) i++;
		int len = i-j;
		for (int k = 1; k <= len; k++) kq += (len-k+1)*k*k;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
