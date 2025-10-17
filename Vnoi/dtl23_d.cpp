#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y,x%y);	
}

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	vector<int> diff(n);
	for (int i = 0; i < n; i++) diff[i] = abs(a[i]-b[i]);
	int k = log2(n)+1;
	vector<vector<int>> sparseT(k,vector<int>(n));
	for (int i = 0; i < n; i++) sparseT[0][i] = diff[i];
	for (int i = 1; i < k; i++) {
		for (int j = 0; j+(1<<i) <= n; j++) {
			sparseT[i][j] = gcd(sparseT[i-1][j], sparseT[i-1][j+(1<<(i-1))]);
		}
	}
	int K_m = 0, m = 0;
	int l = 1, r = n;
	while (l <= r) {
		int d = (l+r)>>1;
		int log_d = log2(d);
		bool c = false;
		for (int i = 0; i+d <= n; i++) {
			int val = gcd(sparseT[log_d][i], sparseT[log_d][i+d-(1<<log_d)]);
			if (val == 1) continue;
			c = true;
			if (K_m < d) K_m = d, m = val;
			else if (K_m == d) m = max(val,m); 
		}
		if (c) l = d+1;
		else r = d-1;
	}
	if (K_m == 0) cout << -1 << endl;
	else cout << K_m << " " << m << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
	return 0;
}
