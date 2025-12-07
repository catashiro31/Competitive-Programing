#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int x, y, z; cin >> x >> y >> z;
	if ((x&y) == (x&z) && (x&z) == (y&z)) cout << "YES" << endl;
	else cout << "NO" << endl;
} 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
