#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> arr(n+1);
	for (int i = 1; i <= n; i++) {
		int c, t; cin >> c >> t;
		arr[i] = {c,t};
	}
	int l = 1, r = 10000, kq = -1;
	while (l <= r) {
		int m = (r+l)>>1;
		vector<int> check(n+1,0);
		bool sc = true;
		for (int i = 1; i <= n; i++) {
			bool c = false;
			for (int j = 1; j <= n; j++) {
//				cout << i << " " << j << " " << abs(arr[j].first-i)*arr[j].second << endl;
				if (abs(arr[j].first-i)*arr[j].second <= m) {
					check[j] = 1;
					c = true;
				}
			}
			if (!c) {
				sc = false;
				break;
			}
		}
//		cout << m << endl;
//		for (int i = 1; i <= n; i++) cout << check[i] << " ";
//		cout << endl;
		for (int i = 1; i <= n; i++) if (!check[i]) sc = false;
		if (sc) kq = m, r = m-1;
		else l = m+1;
	}
	cout << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
