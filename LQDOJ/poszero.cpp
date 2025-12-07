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
	int l = 1, r = s.size(), kq = -1;
	while (l <= r) {
		int m = (l+r)/2;
		if(s[m-1] == '1') r = m-1;
		else kq = m, l = m+1;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
