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
	set<int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.insert(x);
	}
	int i = 0;
	for (auto x : a) {
		if (x != i) {
			cout << i << endl;
			return;
		}
		i++;
	}
	cout << a.size() << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
