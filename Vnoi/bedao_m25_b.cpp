#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
ll gcd(ll a, ll b) {
	if (!b) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a, ll b, ll n) {
	if (a == -1 || b == -1) return -1;
	ll g = gcd(a,b);
	if (a/g > n/b) return -1;
	return (a/g)*b;
}
ll ct(ll x, ll q) {
	if (q == -1 || x%q) return 0;
	x /= q;
	ll ans = 0;
	for (ll i = 1; i*i <= x; i++) {
		if (x % i == 0) {
			ans++;
			if (i != x/i) ans++;
		}
	}
	return ans;
}
void solve() {
	ll n, a, b , c; cin >> n >> a >> b >> c;
	ll ab = lcm(a,b,n), ac = lcm(a,c,n), bc = lcm(b,c,n);
	ll abc = lcm(ab,c,n);
	ll kq = ct(n,ab) + ct(n,bc) + ct(n,ac) - 2*ct(n,abc);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
