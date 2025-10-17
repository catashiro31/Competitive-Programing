#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> a(m);
	for (int &x : a) cin >> x;
	vector<vector<int>> prefix((1<<n),vector<int>(m+1));
	for (int i = 0; i < (1<<n); i++) prefix[i][0] = i;
	for (int i = 0; i < (1<<n); i++) {
		for (int j = 1; j <= m; j++) {
			int bit = (prefix[i][j-1]%(1<<a[j-1]))*(1<<(n-a[j-1])) + (prefix[i][j-1]/(1<<a[j-1]));
			prefix[i][j] = prefix[i][j-1] ^ bit;
		}
	}
	
	while (q--) {
		int x, l, r; cin >> x >> l >> r;
		int kq = x^(prefix[x][r]^prefix[x][l-1]);
		cout << kq << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
