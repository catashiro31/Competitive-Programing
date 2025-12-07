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
	vector<int> prefix(n,0);
	int kq = LLONG_MAX, l = -1, r = -1;
	for (int i = 1; i < n; i++) {
		string s; cin >> s;
		if (s == "Patrik") {
			int t; cin >> t;
			int val = t-prefix[i-1];
			if (kq > val) kq = val, l = i, r = i+1;
			prefix[i] = prefix[i-1] + val; 
		} else {
			int y, t; cin >> y >> t;
			int val = prefix[y-1] + t - prefix[i-1];
			if (kq > val) kq = val, l = i, r = i+1;
			prefix[i] = prefix[i-1] + val;
		}
	}
	cout << kq << " " << l << " " << r; 
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
