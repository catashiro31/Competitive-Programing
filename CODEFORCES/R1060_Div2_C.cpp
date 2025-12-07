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
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<bool> cnt(MAXN, false);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;
	int kq = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j*j <= a[i]+1; j++) {
			if ((a[i]+1) % j) continue;
			if (j > 1 && cnt[j]) kq = min(kq,1LL);
			if (cnt[(a[i]+1)/j]) kq = min(kq,1LL);
		}
		if (a[i] > 1 && cnt[a[i]]) kq = min(kq,0LL);
		for (int j = 1; j*j <= a[i]; j++) {
			if (a[i] % j) continue; 
			if (j > 1 && (cnt[j] || cnt[a[i]/j])) kq = min(kq,0LL);
			cnt[j] = true;
			cnt[a[i]/j] = true;
		}
	}
	vector<bool> rcnt(MAXN,0);
	for (int i = n-1; i >= 0; i--) {
		for (int j = 1; j*j <= a[i]+1; j++) {
			if ((a[i]+1) % j) continue;
			if (j > 1 && cnt[j]) kq = min(kq,1LL);
			if (cnt[(a[i]+1)/j]) kq = min(kq,1LL);
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