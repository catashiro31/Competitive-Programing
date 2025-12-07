#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define psb push_back
void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int,int>> arr;
	arr.psb({0,0});
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.psb({a,b});
	}
	int kq = 0;
	for (int i = 1; i <= n; i++) {
		int d = arr[i].fi - arr[i-1].fi;
		if (arr[i].se == arr[i-1].se) {
			if (d&1) kq += d-1;
			else kq += d;
		} else {
			if (d&1) kq += d;
			else kq += d-1;
		}
	}
	if (arr[n].fi == m) cout << kq << endl;
	else cout << kq+m-arr[n].fi << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}