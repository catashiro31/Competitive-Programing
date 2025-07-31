#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
long long Gcd(long long a, long long b) {
	if (!b) return a;
	else return Gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	while (q--) {
		long long a, b; cin >> a >> b;
		long long ucln = Gcd(abs(a),abs(b));
		a /= ucln, b/= ucln;
		if (a+b == 0) cout << 0 << " " << 0 << endl;
		else {
			if (a < 0 && b < 0) cout << abs(a) << " " << abs(b) << endl;
			else {
				if (a + b > 0) cout << a << " " << b << endl;
				else cout << -a << " " << -b << endl;
			}
		}
	}
}
