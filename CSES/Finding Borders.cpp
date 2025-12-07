#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
void solve() {
	string s; cin >> s;
	int n = sz(s);
	vector<ll> hashT(n+1,0);
	for (int i = 1; i <= n; i++) hashT[i] = (hashT[i-1]*31+s[i-1]-'a'+1)%MOD;
	vector<ll> p(n+1,1);
	for (int i = 1; i <= n; i++) p[i] = (p[i-1] * 31) %MOD;
	auto get_hash = [&](int u, int v) {
		return (hashT[v] - (hashT[u] * p[v-u]) % MOD + MOD) % MOD;	
	};
	for (int i = 1; i < n; i++) {
		int l = 1, r = i;
		ll hash = get_hash(l-1,r), rhash = get_hash(n-r,n-l+1);
//		cout << hash << " " << rhash << endl;
//		cout << l-1 << " " << r << " -- "<< n-r << " " << n-l+1 << endl;
		if (hash == rhash) cout << i << " ";
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
