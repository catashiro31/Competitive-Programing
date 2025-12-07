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
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int cmax = -1, kq = 0;
	for (int i = 0; i < n; i++) {
		cmax = max(cmax,a[i]);
		if (i % 2 == 1) a[i] = cmax;
	}
	
	for (int i = 0; i < n; i+=2) {
		int diff = 0;
		if (i > 0) diff = max(diff,a[i]-a[i-1]+1);
		if (i < n-1) diff = max(diff,a[i]-a[i+1]+1);
		kq += diff;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
