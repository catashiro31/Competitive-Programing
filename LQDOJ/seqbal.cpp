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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> pos(2e5+5,LLONG_MAX);
	const int val = 1e5;
	int dif = 0, kq = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) dif++;
		else dif--;
		kq = max(kq,i-pos[val+dif]);
		pos[val+dif] = min(pos[val+dif],i);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
