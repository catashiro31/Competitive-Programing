#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
#define fi first
#define se second

void solve() {
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	vector<pair<ll,ll>> hashT(n+1,{0,0});
	for (int i = 1; i <= n; i++) {
		hashT[i].fi = (1LL*hashT[i-1].fi*31 + s1[i-1]-'a'+1) % MOD;
		hashT[i].se = (1LL*hashT[i-1].se*313 + s1[i-1]-'a'+1) % MOD;
	}
	vector<pair<ll,ll>> p(n+1,{1,1});
	for (int i = 1; i <= n; i++) {
		p[i].fi = (1LL*p[i-1].fi*31)%MOD;
		p[i].se = (1LL*p[i-1].se*313)%MOD;
	}
	auto get_hash = [&](int u, int v) {
		ll res1 = (hashT[v].fi - (hashT[u].fi*p[v-u].fi)%MOD + MOD) %MOD;
		ll res2 = (hashT[v].se - (hashT[u].se*p[v-u].se)%MOD + MOD) %MOD;
		return make_pair(res1, res2);
	};
	pair<ll,ll> hash = {0, 0};
	for (int i = 0; i < m; i++) {
		hash.fi = (1LL*hash.fi*31 + s2[i]-'a'+1)%MOD;
		hash.se = (1LL*hash.se*313 + s2[i]-'a'+1)%MOD;
	}
	int kq = 0;
	for (int i = 1; i+m-1 <= n; i++) {
		int l = i, r = i+m-1;
		pair<ll,ll> hash_s1 = get_hash(l-1,r);
		if (hash_s1 == hash) kq++;
	}
	cout << kq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
