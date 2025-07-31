#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,q; cin >> n >> q;
	long long prefix_sum[n];
	for (int i = 0; i < n; i++) {
		if (i == 0) cin >> prefix_sum[i];
		else {
			long long x; cin >> x;
			prefix_sum[i] = x + prefix_sum[i-1];
		}
	}
	while(q--) {
		int l, r; cin >> l >> r;
		if (l == 0) cout << prefix_sum[r-1];
		else cout << prefix_sum[r-1] - prefix_sum[l-1];
		cout << endl;
	}
	return 0;
}
