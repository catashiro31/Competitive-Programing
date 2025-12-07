#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, l, d; cin >> n >> l >> d;
	vector<int> h(n+1);
	for (int i = 1; i <= n; i++) cin >> h[i];
	int k = log2(n);
	vector<vector<pair<int,int>>> sparseT(k+1,vector<pair<int,int>>(n+1));
	for (int i = 1; i <= n; i++) sparseT[0][i] = {h[i], h[i]};
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j + (1<<i) - 1 <= n; j++) {
			sparseT[i][j].first = min(sparseT[i-1][j].first, sparseT[i-1][j+(1<<(i-1))].first);
			sparseT[i][j].second = max(sparseT[i-1][j].second, sparseT[i-1][j+(1<<(i-1))].second);
		}
	}
	int j = 1, kq = 0;
	for (int i = 1; i <= n; i++) {
		while (j < i) {
			int lg = log2(i-j+1);
			int cmin = min(sparseT[lg][j].first, sparseT[lg][i-(1<<lg)+1].first);
			int cmax = max(sparseT[lg][j].second, sparseT[lg][i-(1<<lg)+1].second);
//			cout << i << " " << j << " " << cmax-cmin << endl; 
			if (cmax - cmin > d) j++;
			else break;
		}
//		cout << j << " " << i << " " << i-j+1-d+1 << endl;
		kq += max(0LL,i-j+1-l);
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
