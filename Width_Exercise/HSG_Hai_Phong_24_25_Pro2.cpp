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
	ll k; cin >> k;
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	ll kq = LLONG_MIN;
	int sl = 1, d = 0;
	ll sum = a[0];
	for (int i = 1; i < n; i++) {
		ll tmp = a[i]-a[i-1];
		if (d == 0 && abs(tmp) == 1) {
			d = tmp, sl++, sum += a[i];
		} else if (d == tmp) {
			sl++, sum += a[i];
		} else if (d == -tmp) {
			if (d != 0 && sum >= k) kq = max(kq,sum/sl);
			d = tmp, sl = 2, sum = a[i-1] + a[i]; 
		} else {
			if (d != 0 && sum >= k) kq = max(kq,sum/sl);
			d = 0, sl = 1, sum = a[i];
		}
	}
	if (kq != LLONG_MIN) cout << kq;
	else cout << "NO";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
