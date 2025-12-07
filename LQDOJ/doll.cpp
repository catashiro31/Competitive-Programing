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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(all(a),[](auto &a, auto &b){
		return a > b;
	});
	multiset<int> s;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i]+k);
		if (it == s.end()) {
			kq += a[i];
			s.insert(a[i]);
		} else {
			s.erase(it);
			s.insert(a[i]);
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
