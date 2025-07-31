#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF INT_MAX
using ll = long long;
using namespace std;
bool check (long long x) {
	int sum = 0;
	while (x) {
		sum += x%10;
		x /= 10;
	}
	return (sum%5 == 0);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long n; cin >> n;
	vector<long> kq;
	for (long i = 2; pow(i,2) <= n; i++) {
		long bp = pow(i,2);
		if (check(bp)) kq.push_back(bp);
	}
	if (kq.size()) {
		for (long vl : kq) cout << vl << " ";
		cout << endl << kq.size();
	} else cout << "INVALID";
}
