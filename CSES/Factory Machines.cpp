#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	ll t; cin >> t;
	vector<ll> k(n);
	for (ll &x : k) cin >> x;
	ll l = 1, r = 1e18;
	ll kq = 0;
	while (l <= r) {
		ll m = (r+l)/2;
		ll sl = 0;
		for (int i = 0; i < n; i++) {
			sl += (m/k[i]);
			if (sl >= t) {
				kq = m, r = m-1;
				break;
			}
		}
		if (sl < t) l = m+1;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}