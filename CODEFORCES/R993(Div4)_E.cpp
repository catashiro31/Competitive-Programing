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
	int t; cin >> t;
	while (t--) {
		ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
		ll tmp = 1;
		ll kq = 0;
		while (l1 * tmp <= r2) {
			ll d = max(l1*tmp,l2), u = min(r1*tmp,r2);
			u -= u%tmp;
			if (d % tmp) d += tmp - d%tmp;
			if (d <= u) kq += (u-d)/tmp+1;
			tmp *= k;
		}
		cout << kq << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
