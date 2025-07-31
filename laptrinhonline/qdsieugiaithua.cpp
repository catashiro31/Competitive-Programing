#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	ll n; cin >> n;
	ll l = 0, r = 1e18;
	ll kq = 0;
	while (l < r) {
		ll m = (l+r)/2;
		ll sl5 = 0, sl2 = 0;
		ll d = m/5;
		while (d) sl5 += d, d/=5;
		d = m/2;
		while (d) sl2 += d, d/=2;
		if (min(sl2,sl5) == n) kq = m;
		if (min(sl2,sl5) >= n) r = m;
		else l = m+1;  
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
