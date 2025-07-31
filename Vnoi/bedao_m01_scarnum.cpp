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
		int n; cin >> n;
		if (n%2 == 0 || n%5 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
