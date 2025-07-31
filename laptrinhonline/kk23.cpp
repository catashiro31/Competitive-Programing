#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int kq[7] = {1,1,2,6,6,3,9};
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		if (x >= 6) cout << kq[6] << endl;
		else cout << kq[x] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
