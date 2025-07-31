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
		int n; cin >> n;
		long x; cin >> x;
		vector<long> arr(n);
		vector<long> kq;
		for (long &k : arr) {
			cin >> k;
			if (k == -1){
				k = x;
				kq.push_back(x);
			} else kq.push_back(k);
		}
		sort(arr.begin(),arr.end());
		if (arr[n/2] == x) {
			cout << "YES" << endl;
			for (long k : kq) cout << k << " ";
			cout << endl;
		} else cout << "NO" << endl;
	}
}
