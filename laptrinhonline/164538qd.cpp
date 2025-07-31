#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long k, n; cin >> k >> n;
	long tmp = k; int kq = 0;
	while (n != 0) {
		kq++;
		kq += tmp - (int)log2(n);
		tmp =(int)log2(n);
		n -= pow(2,(int)log2(n));
	}
	cout << kq-1;
	return 0;
}
