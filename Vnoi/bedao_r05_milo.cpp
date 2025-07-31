#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long n; cin >> n;
	map<long,bool> check;
	long kq = 0;
	while (!check[n]) {
		kq++;
		check[n] = true;
		n++;
		if (n % 10 == 0) n /= 10;
	}
	cout << kq;
}