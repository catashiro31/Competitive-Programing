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
	int m, k; cin >> m >> k;
	vector<pair<double,int>> space(m);
	for (int i = 0; i < m; i++) {
		int n; cin >> n;
		int color; cin >> color;
		double S = 0;
		vector<pair<int,int>> vi(n);
		for (int j = 0; j < n; j++) {
			int x, y; cin >> x >> y;
			vi[j] = {x,y};
		}
		for (int j = 0; j < n; j++) {
	        int p = (j + 1) % n;
	        S += vi[j].first * vi[p].second - vi[p].first * vi[j].second;
	    }
	    S /= 2;
		space[i] = {S,color};
	}
	sort(all(space),[](auto &a, auto &b){
		return a.fi < b.fi;
	});
	double kq = 0;
	for (int i = 0; i < m; i++) {
		for (int c = 1; c <= m; c++) {
			int j = i, tmp = 0;
			double sum = 0;
			while(j < m && tmp <= k) {
				sum += space[j].fi - (j >= 1 ? space[j-1].fi : 0);
				if (space[j].se != c) tmp++;
				if (tmp > k) sum -= space[j].fi - (j >= 1 ? space[j-1].fi : .0);
				j++;
			}
			kq = max(kq, sum);
		}
	}
	cout << fixed << setprecision(1) << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
