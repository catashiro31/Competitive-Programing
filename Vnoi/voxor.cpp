#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n+1);
	vector<vector<int>> BIT(31,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin()+1,a.end());
	vector<vector<int>> prefix(31,vector<int>(n+1,0));
	for (int k = 30; k >= 0; k--) {
		for (int i = 1; i <= n; i++) prefix[k][i] = prefix[k][i-1] + ((a[i]>>k)&1);
	}
	

	auto get_kq = [&](int xr, int x) {
		int l = 1, r = n;
		for (int k = 30; k >= 0; k--) {
			if ((xr>>k)&1) {
				int cmin = prefix[k][r] - prefix[k][l-1], cmax = r-l+1-cmin;
				if (x <= cmax) {
					r = r - cmin;
				} else {
					l = r - cmin+1;
					x -= cmax;
				}
			} else {
				int cmax = prefix[k][r] - prefix[k][l-1], cmin = r-l+1-cmax;
				if (x <= cmax) {
					l = r - cmax+1;
				} else {
					r = r - cmax;
					x -= cmax;
				}
			}
		}
		return (a[l+x-1]^xr);
	};
	
	stack<pair<int,int>> query;
	int xr = 0;
	while (q--) {
		string t; cin >> t;
		if (t == "FIND") {
			int x; cin >> x;
			query.push({1,x});
		} else {
			int x; cin >> x;
			xr ^= x;
			query.push({2,x});
		}
	}
	vector<int> kq;
	while(!query.empty()) {
		auto [t,x] = query.top(); query.pop();
		if (t == 1) {
			kq.push_back(get_kq(xr,x));
		} else xr ^= x; 
	}
	reverse(all(kq));
	for (int x : kq) cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
