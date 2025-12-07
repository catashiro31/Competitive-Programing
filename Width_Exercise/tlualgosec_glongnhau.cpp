#include<bits/stdc++.h>
using namespace std;
#define psb push_back
#define int long long

const int MOD = 1000000000;

int g(int x) {
	int res = 0;
	res = (res + (x*x) % MOD) % MOD;
	res = (res + (x*2) % MOD) % MOD;
	res = (res + 3) % MOD;
	return res;
}

void solve() {
	int n, x; cin >> n >> x;
	unordered_map<int,int> vis;
	int base = g(x);
	if (n == 1) cout << base << endl;
	vis[base] = 1;
	vector<int> path;
	path.psb(-1);
	path.psb(base);
	for (int i = 2; i <= n; i++) {
		base = g(base);
		if (vis[base] != 0) {
			int len_cycle = i - vis[base];
			cout << vis[base] + (n % len_cycle) << endl; 
			return;
		} else {
			vis[base] = i;
			path.psb(base);
		}
	}
	cout << base << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}