#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
ll GCD(ll a, ll b) {
	if (b == 0) return a;
	return GCD(b,a%b);
}
ll sl(ll x, ll y) {
	if (y == 0 || x % y) return 0;
	ll ans = 0;
	x /= y;
	for (int i = 1; i*i <= x; i++) {
		if (x % i == 0) {
			if (i < x/i) ans++;
			ans++;
		}
	}
	return ans;
}
void solve() {
	ll N, A, B, C; cin >> N >> A >> B >> C;
	ll AB, BC, AC, ABC;
	ll gab = GCD(A,B), gbc = GCD(B,C), gac = GCD(A,C); 
	if (A/gab <= N/B) AB = A*(B/GCD(A,B));
	else AB = 0;
	if (B/gbc <= N/C) BC= B*(C/GCD(B,C));
	else BC = 0;
	if (C/gac <= N/A) AC = A*(C/GCD(A,C));
	else AC = 0;
	if (AB/GCD(AB,C) <= N/C) ABC = AB*(C/GCD(AB,C));
	else ABC = 0;
	ll kq = sl(N,AB) + sl(N,BC) + sl(N,AC) - 2*sl(N,ABC);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
