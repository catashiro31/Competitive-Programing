#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int t; cin >> t;
	while (t--) {
		long y,x; cin >> y >> x;
		long cmax = max(y,x);
		if (cmax % 2) {
			if (cmax == x) cout << 1LL*x*x-y+1;
			else cout << 1LL*(y-1)*(y-1)+x;
		} else {
			if (cmax == y) cout << 1LL*y*y-x+1;
			else cout << 1LL*(x-1)*(x-1)+y;
		}
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}