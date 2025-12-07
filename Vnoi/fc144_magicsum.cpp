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
	vector<int> prefix(1e6+5);
	prefix[0] = 0;
	for (int i = 1; i < 1e6+5; i++) prefix[i] = prefix[i-1] + i;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		kq += prefix[b] - prefix[a-1];
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
