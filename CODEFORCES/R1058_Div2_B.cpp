#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	int val = 2;
	vector<int> a(n);
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		int dif = b[i]-b[i-1];
		if (dif < i+1) a[i] = a[i-dif];
		else a[i] = val++;
	}
	for (int x : a) cout << x << " ";
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
