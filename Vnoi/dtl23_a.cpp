#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin() x.end()
#define psb push_back()
ll log_p (ll n, ll p) {
	ll res = 0;
	while (n % p == 0) n /= p, res++;
	if (n != 1) return LLONG_MIN;
	return res;
}

void solve() {
	ll n; cin >> n;
	if (n == 0 || n == -1 || n == 1) {
		cout << "Piccolo" << endl;
		return;
	}
	if (n > 0 ) {
		ll sqrt_n = sqrt(n);
		if (sqrt_n*sqrt_n == n) {
			cout << "Piccolo" << endl;
			return;
		}
	}
	for (ll i = 2; i*i*i <= abs(n); i++) {
		if (log_p(n,i) >= 3) {
			cout << "Piccolo" << endl;
			return;
		} 
		if (log_p(n,-i) >= 3) {
			cout << "Piccolo" << endl;
			return;
		}
	}
	cout << "Majin Buu" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) solve();
	return 0;
}
