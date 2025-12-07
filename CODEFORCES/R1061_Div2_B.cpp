#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
#define endl '\n'

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int cnt = 0;
	for (char x : s) if (x == 'A') cnt++;
	while(q--) {
		int a; cin >> a;
		if (cnt == n) {
			cout << a << endl;
			continue;
		}
		int kq = 0, i = 0;
		while(a != 0) {
			i = i % n;
			if (s[i] == 'A') a-=1, kq++;
			else a/=2, kq++;
			i++;
		}
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
