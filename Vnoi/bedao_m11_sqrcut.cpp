#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		long a, b; cin >> a >> b;
		long kq = 0;
		while (a != b) {
			if (a < b) swap(a,b);
			a -= b;
			kq++;
		}
		cout << kq << endl;
	}
}
