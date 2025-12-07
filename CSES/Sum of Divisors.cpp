#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	int kq = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n % i != 0) continue;
		kq = (kq + i) % MOD;
		if (n/i != i) kq = (kq + n/i) % MOD;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
