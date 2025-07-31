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
		long a, b; cin >> a >> b;
		long tmp = max(a,b) - min(a,b);
		if (a >= b) a -= 2*tmp, b -= tmp;
		else a -= tmp, b -= 2*tmp;
		if (a < 0) cout << "NO" << endl;
		else {
			if (a % 3) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
