#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	ll m; cin >> m;
	vector<pair<ll,ll>> hb(n);
	for (auto &x : hb) cin >> x.fi >> x.se;
	int i = 0, j = 0;
	ll sum = 0;
	multiset<ll> ms;
	ll kq = LLONG_MAX;
	while (j < n) {
		sum += hb[j].fi;
		ms.insert(hb[j].se);
		if (sum >= m) kq = min(kq,*ms.rbegin());
		while (sum-hb[i].fi >= m) {
			ms.erase(ms.find(hb[i].se));
			kq = min(kq,*ms.rbegin());
			sum -= hb[i].fi;
			i++;
		}
		j++;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("hayfeast.in","r",stdin);
//	freopen("hayfeast.out","w",stdout);
	solve();
}
