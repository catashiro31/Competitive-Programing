#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, m; cin >> a >> b >> m;
	vector<bool> check(a+b);
	while (m--) {
		int x, y; cin >> x >> y;
		check[--x] = 1;
		check[--y+a] = 1;
	}
	for (bool x : check) cout << (x ? "Yes" : "No" )<< endl;
}
