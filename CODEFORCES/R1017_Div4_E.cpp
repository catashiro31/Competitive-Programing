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
	vector<int> a(n);
	vector<vector<int>> grid(n,vector<int>(30,0));
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
		for (int j = 0; j < 30; j++) {
			if ((x>>j)&1) grid[i][j] = 1;
		}
	}
	vector<vector<int>> sl(30,vector<int>(2,0));
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[j][i] == 1) sl[i][1]++;
			else sl[i][0]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	int kq = 0;
	for (int i = 0; i < n; i++) {
		int val = 0;
		for (int j = 0; j < 30; j++) {
			int v = (1<<j);
			if (grid[i][j] == 0) continue;
			val += (sl[j][0]-sl[j][1]) * v;
		}
		kq = max(kq,sum+val);
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
