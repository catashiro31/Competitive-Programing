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
	string name_users[n];
	int users[n][5][5];
	for (int i = 0; i < n; i++) {
		cin >> name_users[i];
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) cin >> users[i][j][k];
		}
	}
	int m; cin >> m;
	vector<bool> c(100,false);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		c[x] = true;
	}
	vector<bool> kq(n,false);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++) {
			int col = 0, row = 0;
			for (int k = 0; k < 5; k++) {
				if (c[users[j][i][k]]) col++;
				if (c[users[j][k][i]]) row++;
			}
			if (col == 5 || row == 5) kq[j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		int chinh = 0, phu = 0;
		for (int j = 0; j < 5; j++) {
			if (c[users[i][j][j]]) chinh++;
			if (c[users[i][j][5-j-1]]) phu++;
		}
		if (chinh == 5 || phu == 5) kq[i] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (kq[i]) cnt++;
	cout << cnt << endl;
	for (int i = 0; i < n; i++) if (kq[i]) cout << name_users[i] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
