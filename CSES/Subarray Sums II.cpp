#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long x; cin >> x;
	long kq = 0;
	map<long long,int> sl; 
	sl[0] = 1;
	long long prefix_sum = 0;
	for (int i = 0; i < n; i++) {
		long k; cin >> k;
		prefix_sum += k;
		kq += sl[prefix_sum-x];
		sl[prefix_sum]++;
	}
	cout << kq;
	return 0;
}
