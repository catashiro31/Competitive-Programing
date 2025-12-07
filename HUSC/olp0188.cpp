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
	pair<int,int> dung = {-1,0}, hung={-1,0};
	for (int i = 0; i < n; i++) {
		int dif1 = arr[i].fi - dung.fi, dif2 = arr[i].fi - hung.fi;
		if (dif1 >= 0 && dif2 >= 0) {
			if (dif1 >= dif2) hung = {arr[i].se, hung.se+1};
			else dung = {arr[i].se, dung.se+1};
		} else if (dif1 >= 0) dung = {arr[i].se, dung.se+1};
		else if (dif2 >= 0) hung = {arr[i].se, hung.se+1};
	}
	cout << dung.se + hung.se;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
