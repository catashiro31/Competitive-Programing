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
	int k; cin >> k;
	vector<ll> x(n);
	for (ll &vl : x) cin >> vl;
	ll l = *max_element(x.begin(),x.end());
	ll r = accumulate(x.begin(),x.end(),0LL);
	ll kq = 0;
	while (l <= r) {
		ll m = (l+r)/2;
		int sl = 1;
		ll sum = 0;
		bool check = true;
		for (int i = 0; i < n; i++) {
			if (x[i] > m) {
				check = false;
				break;
			}
			if (sum + x[i] > m) {
				sl++;
				sum = x[i];
			} else sum += x[i];
		}
		if (check) {
			if (sl > k) l = m+1;
			else kq = m, r = m-1;
		} else l = m+1;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
