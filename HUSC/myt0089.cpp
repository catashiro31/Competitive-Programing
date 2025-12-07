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

int powup(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

void solve() {
	int n, k; cin >> n >> k;
	int kq = powup(n,k) + powup(n,n) + 2*powup(n-1,k) + 2*powup(n-1,n-1);
	cout << kq%MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
