#include <bits/stdc++.h>
#define endl '\n'
#define mod 10000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long long prefix_sum = 0;
	int kq = INT_MIN;
	map<int,int> pos;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		prefix_sum += x;
		int tmp = prefix_sum%7;
		if (tmp == 0) kq = max(kq,i-0);
		else {
			if (!pos[tmp]) pos[tmp] = i;
			else kq = max(kq,i-pos[tmp]);
		}
	}
	cout << kq;
}
