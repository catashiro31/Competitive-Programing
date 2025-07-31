#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, q; cin >> n >> q;
	ll left = 0, right = 0;
	while (q--) {
		int l,r; cin >> l >> r;
		ll s; cin >> s;
		if (l >= 1 && r < n) left += s;
		if (r <= n && l > 1) right += s; 
	}
	cout << max(left,right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
