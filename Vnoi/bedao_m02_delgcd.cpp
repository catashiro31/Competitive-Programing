#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
long gcd(long a, long b) {
	if (!b) return a;
	else return gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	if (n == 1) {
		if (a[0] == 1) cout << 0;
		else cout << -1;
	} else {
		long tmp = a[0];
		for (int i = 1; i < n; i++) {
			tmp = gcd(tmp,a[i]);
		}
		if (tmp == 1) cout << 0;
		else cout << -1;
	}
}
