#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define MOD 1000000007
void solve() {
	string str; cin >> str;
	string rstr = str;
	reverse(all(rstr));
	int n = sz(str);
	ll base = 31;
	vector<ll> p(n+1,1);
	for (int i = 1; i <= n; i++) p[i] = (p[i-1]*base) % MOD;
	vector<ll> hashT(n+1,0), rhashT(n+1,0);
	for (int i = 1; i <= n; i++) {
		hashT[i] = (hashT[i-1]*31 + str[i-1]-'a') % MOD;
		rhashT[i] = (rhashT[i-1]*31 + rstr[i-1]-'a') % MOD;
	}
	auto get_hash = [&](const vector<ll> & hash, int u, int v) {
		return ((hash[v] - hash[u]*p[v-u]) % MOD + MOD) % MOD;
	};
	int kq = 0;
	string show = "";
	int l = 1, r = n;
	if (r % 2 == 0) r--;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (m % 2 == 0) m--;
		bool check = false;
		int p = -1;
		for (int i = 1; i+m-1 <= n; i++) {
			int u = i, v = i+m-1;
			int hash_v = get_hash(hashT,u,v), rhash_v = get_hash(rhashT,n-v+1,n-u+1);
			if (hash_v == rhash_v) {
				check = true;
				p = i;
				break;
			}
		}	
		if (check) {
			if (m > kq) kq = m, show = str.substr(p-1,m);
			l = m+2;	
		} else r = m-2;
	}
	l = 2, r = n;
	if (r&1) r--;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (m % 2 != 0) m--;
		bool check = false;
		int p = -1;
		for (int i = 1; i+m-1 <= n; i++) {
			int u = i, v = i+m-1;
			int hash_v = get_hash(hashT,u,v), rhash_v = get_hash(rhashT,n-v+1,n-u+1);
			if (hash_v == rhash_v) {
				check = true;
				p = i;
				break;
			}
		}
		if (check) {
			if (m > kq) kq = m, show = str.substr(p-1,m);
			l = m+2;	
		} else r = m-2;
	}
	cout << show << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
