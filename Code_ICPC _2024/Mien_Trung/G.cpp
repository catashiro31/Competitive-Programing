#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int p,q; cin >> p >> q;
	if ((p == 1 && q== 1) || (p == n && q == 1) || (p == 1 && q == m) || (p == n && q == m)) cout << 3;
	else if (p == 1 || q == 1 || p == n || q == m) cout << 5;
	else cout << 8;
}
