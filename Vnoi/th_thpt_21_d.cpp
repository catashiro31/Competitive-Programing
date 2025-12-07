#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

ll get_log(ll x, ll log) {
	ll res = 0;
	while (x) {
		res++;
		x /= log;
	}	
	return res-1;
}

void solve() {
	ll l, r; cin >> l >> r;
	vector<bool> c(1e6+1,false);
	vector<ll> snt;
	for (ll i = 2; i <= 1e6; i++) {
		if (c[i]) continue;
		snt.psb(i);
		for (ll j = i*i; j <= 1e6; j+=i) c[j] = true; 
	}
	vector<ll> exp;
	for (int i = 1; i < sz(snt); i++) exp.psb(snt[i]-1);
	ll kq = 0;
	for (ll i = 0; i < snt.size(); i++) {
		if (snt[i]*snt[i] > r) break;
		ll logi_l = get_log(l,snt[i]), logi_r = get_log(r,snt[i]);
		ll lb = lower_bound(all(exp),logi_l) - exp.begin();
		ll ub = upper_bound(all(exp),logi_r) - exp.begin();
		if (pow(snt[i],exp[lb]) < l) lb++;
		kq += max(0LL,ub-lb);
	}
	cout << kq;
}
int main() {
//	freopen("BAI4.INP","r",stdin);
//	freopen("BAI4.OUT","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
