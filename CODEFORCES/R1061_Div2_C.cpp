#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
#define endl '\n'

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	map<int,int> cnt;
	for (int i = 0; i < n; i++) cnt[a[i]]++;
	int kq = -1;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] + k >= n) {
			kq = max(kq, a[i]);
		}
	}
	int cmax = *max_element(all(a));
	cmax = sqrt(cmax);
	for (int i = cmax; i >= 1; i--) {
		bool c = true;
		int t = k;
		for (int x : a) {
			if (x % i == 0) continue;
			int sl = x/i;
			if (sl < 4) {
				if (x == i*3) continue;
				else {
					if (t) t--;
					else {
						c = false;
						break;
					}
				}
			}
		}
		if (c) {
			kq = max(kq,i);
			break;
		}
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; cin >> t;
	while(t--) solve();
}
