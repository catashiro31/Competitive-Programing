#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	ll lf, rt; cin >> lf >> rt;
	ll tmp = 2, kq = 0;
	while (tmp <= rt) {
		ll r = rt, l = lf;
		r -= r%tmp;
		if (l % tmp) l += (tmp - l%tmp);
		kq += (r-l)/tmp + 1;
		tmp *= 2;
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
