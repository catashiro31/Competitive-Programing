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
	vector<bool> c(1e6+5,true);
	vector<int> snt;
	for (int i = 2; i <= 1e6; i++) {
		if (c[i]) snt.psb(i);
		for (int j = i*i; j <= 1e6; j+=i) c[j] = false;
	}
	for (int i = 0; i < sz(snt); i++) {
		int val = n, cnt = 0;
		while (val % snt[i] == 0) {
			val /= snt[i], cnt++;
		}
		if (val == 1 && cnt > 1) {
			cout << snt[i] << " " << cnt << endl;
			return;
		} 
	}
	int root_n = sqrt(n);
	if (root_n * root_n == n) {
		bool check = true;
		for (int i = 2; i*i <= root_n; i++) {
			if (root_n % i == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << root_n << " " << 2 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
