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
	int x; cin >> x;
	vector<bool> c(1e5+5,false);
	c[1] = true;
	for (int i = 2; i*i <= x; i++) {
		int base = i*i;
		while (base <= x) c[base] = true, base *= i;
	}
	while (!c[x]) x--;
	cout << x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
