#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int tcs(int k) {
	int res = 0;
	while (k) {
		res += k%10;
		k /= 10;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	if (n/10 == 0) {
		n %= 10;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (j+i == 10) n--;
				if (!n) {
					cout << i << j;
					return 0;
				}
			}
		}
	} else {
		int c = tcs(n/10);
		cout << n/10;
		n = n%10+1;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if ((c+ j + i )% 10 == 0) n--;
				if (!n) {
					cout << i << j;
					return 0; 
				}
			}
		}
	}
}
