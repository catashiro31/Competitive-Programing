#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m; cin >> m;
	while (m--) {
		long long t, n, k; cin >> t >> n >> k;
		if (k < t) cout << 0 << endl;
		else cout << ((k-t)/n)+1 << endl;
	}
}
