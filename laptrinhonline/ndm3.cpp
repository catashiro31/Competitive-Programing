#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	vector<ll> snt;
	vector<bool> c(1e8+1,true);
	for (ll i = 2; i <= 1e8; i++) {
		if (!c[i]) continue;
		snt.pb(i);
		cout << i << endl;
		for (ll j = i*i; j <= 1e8; j += i) c[j] = false;
	}
	while (t--) {
		long l,r; cin >> l >> r;
		cout << upper_bound(snt.begin(),snt.end(),r) - lower_bound(snt.begin(),snt.end(),l) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
