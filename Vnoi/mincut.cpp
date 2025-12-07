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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> grid(n+1,vector<int>(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> grid[i][j];
	}
	vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + grid[i][j];
	}
	auto cal = [&](int x1, int y1, int x2, int y2) {
		return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];	
	};
	while (k--) {
		int x, y, u, v; cin >> x >> y >> u >> v;
		int kq = LLONG_MAX;
		int low = x, high = u-1;
		while (low <= high) {
			int mid = (high+low)>>1;
			int hcn1 = cal(x,y,mid,v), hcn2 = cal(mid+1,y,u,v);
			kq = min(kq,abs(hcn1-hcn2));
			if (hcn1 < hcn2) low = mid+1;
			else high = mid-1;
		}
		low = y, high = v-1;
		while (low <= high) {
			int mid = (high+low)>>1;
			int hcn1 = cal(x,y,u,mid), hcn2 = cal(x,mid+1,u,v);
			kq = min(kq,abs(hcn1-hcn2));
			if (hcn1 < hcn2) low = mid+1;
			else high = mid-1;
		}
		cout << kq << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
