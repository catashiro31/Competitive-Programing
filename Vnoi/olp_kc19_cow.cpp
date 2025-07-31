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
	ll a, b; cin >> a >> b;
	ll l = LLONG_MAX;
	while (n--) {
		ll x,y,r; cin >> x >> y >> r;
		ll tmp = pow(a-x,2) + pow(b-y,2);
		ll d = sqrt(tmp);
		if (tmp == pow(d,2)) d -= 1;
		l = min(l,d-r);
	}
	cout << l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
