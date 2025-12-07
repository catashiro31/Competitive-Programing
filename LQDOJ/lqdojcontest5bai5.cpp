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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int cur = a[0], kq = 0;
	for (int i = 0; i < n; i++) {
		cur = gcd(cur,a[i]);
		if (cur == i+1) cout << 1 << " ";
		else cout << 0 << " ";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
