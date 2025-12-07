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
	string xauT; cin >> xauT;
	int m = sz(xauT);
	vector<vector<int>> val(3005,vector<int>(3005,-1));
	for (int i = 1; i <= m/2; i++) {
		for (int j = 0; j + 2*i <= m; j++) {
			int cnt = 0;
			for (int k = 0; k < i; k++) if (xauT[j+k] != xauT[j+i+k]) cnt++;
			val[i][j] = cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		int kq = 0;
		for (int j = m/2; j >= 1; j--) {
			if (kq) break;
			for (int h = 0; h + 2*j <= m; h++) {
				if (val[j][h] <= k) kq = j;
				if (kq) break;
			}
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
