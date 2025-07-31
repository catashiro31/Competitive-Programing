#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
long long nghich_dao(long long &pos, long long mod) {
	long long kq = 1;
	while (mod > 0) {
		if (mod % 2 == 1) {
			kq = (kq*pos)%m; 
		}
		pos = (pos*pos)%m;
		mod /= 2;
	}
	return kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a; cin >> a;
	int n; cin >> n;
	long long tu = 1;
	for (int i = 1; i <= n; i++) {
		tu = ((a+i)%m*tu)%m;
	}
	long long mau = 1;
	for (int i = 1; i <= n; i++) {
		mau = (i*mau)%m;
	}
	cout << (tu*nghich_dao(mau, m-2))%m;
}
