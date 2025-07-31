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
	int n; cin >> n;
	ll sll = 0, slc = 0;
	ll tl = 0, tc = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (x%2) tl = (tl+x)%mod, sll++;
		else tc = (tc+x)%mod, slc++;
	} 
	if (sll && slc) cout << ((tl*slc)%mod + (tc*sll)%mod)%mod;
	else cout << 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
