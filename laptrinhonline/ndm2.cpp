#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;

ll ccount(ll k) {
	return k - (k/3) - (k/10) + (k/30);

}
void solve() {
	int t; cin >> t;
	while (t--) {
		ll k; cin >> k;
		ll l = 1, h = 1e18;
		ll ans = -1;
		while (l <= h) {
			ll m = (l+h)/2;
			if (ccount(m) >= k) {
				ans = m;
				h = m - 1; 
			} else l = m + 1;
		}
		cout << ans << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
