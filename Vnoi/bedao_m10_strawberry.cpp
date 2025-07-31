#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long x; cin >> x;
	long arr[n];
	for (long &k : arr) cin >> k;
	long long kq = 0;
	for (long k : arr) {
		long z = x;
		if (z % k == 0) {
			z -= k;
			kq += ((z-k)/k+1)*(z+k)/2;
		} else {
			z -= z%k;;
			kq += ((z-k)/k+1)*(z+k)/2;
		}
	}
	cout << kq;
}
