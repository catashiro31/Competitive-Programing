#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int a, b, c; cin >> a >> b >> c;
	int m; cin >> m;
	vector<ll> usb, ps;
	for (int i = 0; i < m; i++) {
		ll x; cin >> x;
		string tp; cin >> tp;
		if (tp == "USB") usb.pb(x);
		else ps.pb(x);
	}
	sort(usb.begin(),usb.end());
	sort(ps.begin(),ps.end());
	int i = 0, j = 0;
	ll kq = 0;
	while (i < usb.size() && i < a) kq += usb[i], i++;
	while (j < ps.size() && j < b) kq += ps[j], j++;
	while (c) {
		if (i < usb.size() && j < ps.size()) {
			if (usb[i] <= ps[j]) kq += usb[i], i++;
			else kq += ps[j], j++;
		} else if (i == usb.size() && j < ps.size()) kq += ps[j], j++;
		else if (i < usb.size() && j == ps.size()) kq += usb[i], i++;
		c--;
	}
	cout << i + j << " " << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
