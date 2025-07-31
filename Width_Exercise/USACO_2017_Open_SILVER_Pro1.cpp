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
	vector<pair<ll,ll>> cows(n);
	for (int i = 0; i < n; i++) {
		ll a,b; cin >> a >> b;
		cows[i] = {b,a};
	}
	sort(cows.begin(),cows.end());
	int l = 0, r = n-1;
	ll kq = 0;
	while (l <= r) {
		kq = max(kq,cows[l].fi+cows[r].fi);
		if (l == r) break;
		ll sll = cows[l].se, slr = cows[r].se;
		cows[l].se -= min(sll,slr);
		cows[r].se -= min(sll,slr);
		if (slr == 0) r--;
		if (sll == 0) l++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	solve();
}
