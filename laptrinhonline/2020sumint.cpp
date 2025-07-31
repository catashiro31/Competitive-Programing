#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	ll n; cin >> n;
	n *= 2;
	vector<pair<ll,ll>> kq;
	for (ll i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			ll j = n/i;
			if ((i+j-1) % 2 == 0) {
				ll tmp = (i+j-1) / 2;
				kq.pb({j-tmp,tmp});
			}
		}
	}
	sort(kq.begin(),kq.end());
	cout << kq.size() << endl;
	for (int i = kq.size()-1; i >= 0; i--) cout << kq[i].fi << " " << kq[i].se << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
