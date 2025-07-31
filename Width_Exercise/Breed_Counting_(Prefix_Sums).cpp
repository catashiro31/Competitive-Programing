#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n, q; cin >> n >> q;
	vector<vector<int>> prefix_sum(3,vector<int> (n+1,0));
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		for (int j = 0; j < 3; j++) {
			if (x-1 == j) prefix_sum[j][i] = prefix_sum[j][i-1] + 1;
			else prefix_sum[j][i] = prefix_sum[j][i-1];
		}
	}
	while (q--) {
		int l, r; cin >> l >> r;
		if (l == 1) {
			cout << prefix_sum[0][r] << " " << prefix_sum[1][r] << " " << prefix_sum[2][r];
		} else {
			cout << prefix_sum[0][r] - prefix_sum[0][l-1] << " ";
			cout << prefix_sum[1][r] - prefix_sum[1][l-1] << " ";
			cout << prefix_sum[2][r] - prefix_sum[2][l-1];
		}
		cout << endl;
	}
	return 0;
}