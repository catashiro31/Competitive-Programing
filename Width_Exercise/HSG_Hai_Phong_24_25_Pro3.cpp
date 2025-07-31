#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int m, n; cin >> m >> n;
	int q = m + n;
	ll suma = 0, sumb = 0;
	int sla = 0, slb = 0;
	vector<pair<int,int>> p;
	vector<pair<int,int>> ab;
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		if (c == 2) sumb += b, slb++;
		if (c == 1) suma += a, sla++;
		if (c == 0) {
			p.pb({abs(a-b),p.size()});
			ab.pb({a,b});
		}
	}
	sort(p.begin(),p.end());
//	for (auto x : p) cout << x.fi << " ";
	for (int i = p.size()-1; i >= 0; i--) {
		if (min(ab[p[i].se].fi,ab[p[i].se].se) == ab[p[i].se].fi) {
			if (sla < m) sla++, suma += ab[p[i].se].fi;
			else {
				while (i >= 0) sumb += ab[p[i].se].se, i--;
			}
		} else {
			if (slb < n) slb++, sumb += ab[p[i].se].se;
			else {
				while (i >= 0) suma += ab[p[i].se].fi, i--;
			}
		}
	}
	cout << suma + sumb;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
