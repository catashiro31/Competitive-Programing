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
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].fi >> arr[i].se;
	sort(all(arr),[](auto &a, auto &b){
		if (a.se != b.se) return a.se < b.se;	
		return a.fi < b.fi;
	});
	int kq = 0, tend = -1;
	for (int i = 0; i < n; i++) {
		if (tend == -1) tend = arr[i].se, kq++;
		else {
			if (tend <= arr[i].fi) tend = arr[i].se, kq++;
		}
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
