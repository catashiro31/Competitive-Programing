#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
ll slcs(ll x) {
	ll ans = 0;
	while (x) ans++, x/= 10;
	return ans;
}
bool check(ll x) {
	while (x) {
		if (x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}
void solve() {
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		ll n = slcs(x);
		ll k = 0;
		ll kq = 10;
		for (ll i = 0; i <= n; i++) {
			for (ll j = 0; j < kq; j++) {
				if (check(x + k * j)) kq = j;
			}
			k += pow(10,i)*9;
		}
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
