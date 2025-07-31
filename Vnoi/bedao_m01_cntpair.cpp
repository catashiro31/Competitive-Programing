#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int le = 0, chan = 0;
	for (int i = 0; i < n; i++) {
		long x; cin >> x;
		if (x%2) le++;
		else chan++;
	}
	cout << 1LL*le*(le-1)/2 + 1LL*chan*(chan-1)/2;
}
