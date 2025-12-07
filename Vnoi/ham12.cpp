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
	int n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	int j = 0;
	while (sz(s) < n+m-1) s = s + s[j], j++;
	int kq = INT_MAX;
	for (int i = 0; i < k; i++) {
		string xau; cin >> xau;
		for (int j = 0; j+m <= sz(s); j++) {
			int cnt = 0;
			for (int h = 0; h < m; h++) {
				if (s[j+h] != xau[h]) cnt++;
			}
			kq = min(kq, cnt);
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
