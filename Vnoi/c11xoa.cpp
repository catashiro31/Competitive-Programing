#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n; cin >> n;
	int kq = 0;
	for (int i = 0; i < (1<<n); i++) {
		if (((i>>0) &1) == 1 && ((i>>(n-1)) & 1) == 1) continue;
		bool ck = true;
		for (int j = 0; j < n-1; j++) {
			if (((i>>j)&1) == 1 && ((i>>(j+1))&1) == 1) ck = false;
		}
		if (ck) kq++;
	}
	cout << kq << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
	return 0;
}
