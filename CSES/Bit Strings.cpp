#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
ll Pow(ll base, ll exp) {
	ll kq = 1;
	while (exp) {
		if (exp % 2) kq = (kq * base)%mod;
		base = (base*base)%mod;
		exp /= 2;
	}
	return kq;
}
void solve() {	
	ll n; cin >> n;
	cout << Pow(2,n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
