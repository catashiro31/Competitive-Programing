#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long ans = 0;
	long long prefix_sum = 0;
	map<int,int> sl;
	sl[0] = 1;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		prefix_sum += x;
		int tmp = (prefix_sum%n+n)%n;
		ans += sl[tmp];
		sl[tmp]++;
	}
	cout << ans;
	return 0;
}
