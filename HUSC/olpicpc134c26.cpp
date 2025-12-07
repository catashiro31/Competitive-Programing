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
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int sl_d = 0, sl_k = 0, sl_o = 0, sl_r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'd') sl_d++;
		else if (s[i] == 'k') sl_k++;
		else if (s[i] == 'o') sl_o++;
		else sl_r++;
	}
	int kq = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m-i; j++) {
			for (int h = 0; h <= m-j-i; h++) {
				int d = sl_d + i, k = sl_k + j, o = sl_o + h, r = sl_r + m-i-j-h;
				int squared = d*d + k*k + o*o + r*r;
				kq = max(kq, squared + 7*min({k/2,r,o/2,d}));	
			}
		}
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
