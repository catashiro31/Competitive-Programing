#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<long> a(n);
	long sum = 0;
	for (long &x : a) {
		cin >> x;
		sum += x;
	}
	for (int i = n; i > 0; i--) {
		if (sum % i == 0) {
			long tmp = sum / i;
			bool c = true;
			for (int j = 0; j < n; j++) {
				tmp -= a[j];
				if (tmp == 0) tmp = sum/i;
				else if (tmp < 0) {
					c = false;
					break;
				}
			}
			if (c && tmp == sum/i) {
				cout << sum/i;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt","r",stdin);
	solve();
}
