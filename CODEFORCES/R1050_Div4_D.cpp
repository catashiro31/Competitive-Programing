#include<bits/stdc++.h>
using namespace std;
#define psb push_back
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'

void solve() {
	int n; cin >> n;
	vector<int> odd;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x&1) odd.psb(x);
		else sum += x;
	}
	if (odd.empty()) cout << 0 << endl;
	else {
		int kq = sum + odd[odd.size()-1];
		if (odd.size() == 1) cout << kq << endl;
		else {
			sort(all(odd));
			int i = 0, j = odd.size()-2;
			while (i < j) {
				kq += odd[j];
				i++, j--;
			}
			cout << kq << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}