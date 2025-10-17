#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n, p; cin >> n >> p;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> prefix(n+1);
	prefix[0] = 0;
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	for (int i = n; i > 0; i--) {
		for (int j = 0; j+i <= n; j++) {
			if (prefix[j+i] - prefix[j] >= p) {
				cout << i << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
