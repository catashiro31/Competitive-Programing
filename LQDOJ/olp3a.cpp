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
	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(all(a));
	vector<int> square_a(n);
	for (int i = 0; i < n; i++) square_a[i] = a[i]*a[i];
	int kq = 0;
	if (t == 3) {
		for (int i = 2; i < n; i++) {
			int l = 0, r = i-1;
			while (l < r) {
				if (a[l] + a[r] <= a[i]) l++;
				else {
					int val = a[i]*a[i] - a[r]*a[r];
					int it = lower_bound(all(square_a),val) - square_a.begin();
					kq += max(0LL,min(it,r)-l);
					r--;
				}
			}
		}
	} else if (t == 1) {
		for (int i = 2; i < n; i++) {
			int l = 0, r = i-1;
			while (l < r) {
				if (a[l] + a[r] <= a[i]) l++;
				else {
					int val = a[i]*a[i] - a[r]*a[r];
					int it = upper_bound(all(square_a),val) - square_a.begin();
					kq += max(0LL, r-max(it,l));
					r--;
				}
			}
		}
	} else {
		for (int i = 2; i < n; i++) {
			int l = 0, r = i-1;
			while (l < r) {
				if (a[l] + a[r] <= a[i]) l++;
				else {
					int val = a[i]*a[i] - a[r]*a[r];
					auto it_low = lower_bound(square_a.begin() + l, square_a.begin() + r, val);
                    auto it_high = upper_bound(square_a.begin() + l, square_a.begin() + r, val);
					kq += it_high - it_low;
					r--;
				}
			}
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
