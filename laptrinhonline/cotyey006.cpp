#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int len(long long a) {
	int i = 0;
	while(a) {
		i++;
		a/=10;
	}
	return i;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long n; cin >> n;
	long long tmp = sqrt(n)+1;
	int kq = INT_MAX;
	for (int i = 1; i <= tmp; i++) {
		if (n%i == 0) {
			int len_x = len(i);
			int len_y = len(n/i);
			kq = min(kq,max(len_x,len_y));
		}
	}
	cout << kq;
}
