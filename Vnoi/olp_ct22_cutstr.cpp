#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
void solve() {
	string s; cin >> s;
	string rs = s;
	reverse(all(rs));
	int n = s.size();
	int t; cin >> t;
	ll base = 31;
	vector<ll> hashT(n+1,0), rhashT(n+1,0), p(n+1,1);
	for (int i = 1; i <= n; i++) hashT[i] = (hashT[i-1]*base + s[i-1]-'a') % MOD;
	for (int i = 1; i <= n; i++) p[i] = (p[i-1]*base) % MOD;
	for (int i = 1; i <= n; i++) rhashT[i] = (rhashT[i-1]*base + rs[i-1]-'a') % MOD;
	auto get_hash = [&](vector<ll> &hash, int l, int r) {
		return ((hash[r] - hash[l]*p[r-l]) % MOD + MOD) % MOD;
	};
	while (t--) {
		int k; cin >> k;
		vector<int> l(k);
		for (int &x : l) cin >> x;
		bool check = false;
		for (int i = 0; i+l[0]-1 <= n; i++) {
			int u = i+1, v = i+l[0];
			ll get_h = get_hash(hashT,u,v);
			ll get_rh = get_hash(rhashT,n-v+1,n-u+1);
			if (get_h == get_rh) check = true;
		}  
		if (check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
