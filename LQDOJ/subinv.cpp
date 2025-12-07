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
	int n; cin >> n;
	string s; cin >> s;
	int sum = 0, cmin = 0;
	int kq = 0, val = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') sum += 1;
		else val += 1, sum -= 1;
		kq = max(kq, sum-cmin);
		cmin = min(cmin,sum);
	}
	if (val == n) cout << n-1 << endl;
	else cout << val+kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
