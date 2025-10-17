#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n; cin >> n; 
	double y0; cin >> y0;
	vector<double> x(n);
	for (double &v : x) cin >> v;
	int m; cin >> m;
	vector<pair<double,double>> xy(m);
	for (int i = 0; i < m; i++) cin >> xy[i].first >> xy[i].second;
	sort(all(x));
	double l = 0, r = 1e7, kq;
	double eps = 1e-7;
	while (r-l > eps) {
		double k = (l+r)/2.0;
		vector<int> prefix(n+1,0);
		for (int i = 0; i < m; i++) {
			double xi = xy[i].first;
            double yi = xy[i].second;
            if ((y0-yi)*(y0-yi) > k*k) continue;
            double dx = sqrt(k*k - (y0-yi)*(y0-yi));
            double left = xi - dx;
            double right = xi + dx;
            int lb = lower_bound(all(x), left) - x.begin();
            int ub = upper_bound(all(x), right) - x.begin();
			prefix[lb]++, prefix[ub]--;
		}
		bool check = prefix[0] > 0;
		for (int i = 1; i < n; i++) {
			prefix[i] += prefix[i-1];
			if (prefix[i] == 0) check = false;
		}
		if (check) kq = k, r = k;
		else l = k;
	}
	cout << fixed << setprecision(8) << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
