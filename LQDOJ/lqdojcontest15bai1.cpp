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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int sum = 0, i = 0;
	while (i < n && sum + a[i] <= m) sum += a[i], i++;
	cout << i;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
