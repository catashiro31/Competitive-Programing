#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	vector<int> a(1e5+1,0);
	while (t--) {
		int q; cin >> q;
		set<int> arr;
		bool kq = true;
		for (int i = 0; i < q; i++) {
			int p, x; cin >> p >> x;
			if (p == 1) {
				a[x]++;
				arr.insert(x);
			} else {
				if (!a[x]) {
					if (!a[0]) {
						kq = false;
					} else a[0]--;
				} else a[x]--;
			}
		}
		if (kq) cout << "YES" << endl;
		else cout << "NO" << endl;
		for (int k : arr) a[k] = 0;
	}
}
