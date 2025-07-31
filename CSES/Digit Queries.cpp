#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int q; cin >> q;
	while (q--) {
		ll k; cin >> k;
		ll i = 1, base = 1;
		while (true) {
			ll count = 9*base*i;
			if (k <= count) break;
			k -= count;
			base *= 10;
			i++;
		}
		ll tmp = base + (k-1)/i;
		ll pos = (k-1)%i;
		string s = to_string(tmp);
		cout << s[pos] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}