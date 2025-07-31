#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
ll modulo(ll base, ll exp) {
	ll ans = 1;
	while (exp) {
		if (exp%2) ans = (ans * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return ans;
}
void solve() {
	vector<ll> gt(1e5+1,1);
	for (ll i = 2; i <= 1e5; i++) gt[i] = (gt[i-1]*i)%mod;
	int n, k; cin >> n >> k;
	ll m = 1;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		m = (m*gt[x])%mod;
	}
	m = modulo(m,mod-2);
	cout << (m*gt[n])%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
