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
	int n, t, a, b; cin >> n >> t >> a >> b;
	vector<int> k(n);
	for (int &x : k) cin >> x;
	for (int i = 1; i < n; i++) k[i] += k[i-1];
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int y = max(0LL,min(i+1,(t-(i+1)*b)/(a-b))), x = i+1 - y;
		if (x == 0) kq = max(kq, k[i]);
		else kq = max(kq, k[i] - k[x-1]);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
