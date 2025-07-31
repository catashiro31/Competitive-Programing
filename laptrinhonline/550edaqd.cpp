#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	long cmin = INT_MAX;
	long cmax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cmin = min(cmin,arr[i]);
			cmax = max(cmax,arr[i]);
		} else {
			cmin = min(cmin,arr[i]);
			cmax = max(cmax,arr[i]);
			cout << cmax-cmin << " ";
		}
	}
}
