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
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int sum = 0;
	set<pair<int,int>> st;
	st.insert({0,1});
	int kq = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		auto it = st.lower_bound({sum-s,INT_MIN});
		if (it != st.end()) {
			auto [v,sl] = *it;
			if (v == sum-s) kq += sl; 
		}
		auto p = st.lower_bound({sum,INT_MIN});
		if (p == st.end()) st.insert({sum,1});
		else {
			auto [v,sl] = *p;
			if (v == sum) {
				st.erase(p);
				st.insert({sum,sl+1});
			} else st.insert({sum,1});
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
