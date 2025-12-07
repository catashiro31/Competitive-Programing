#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	int kq = 0;
	for (int i = 1; i <= n; i++) {
		int k = 1;
		for (int j = i; j <= n; j++) {
			int sum = prefix[j] - prefix[i-1];
			if (sum&1) continue;
			while(prefix[k]-prefix[i-1] < sum/2) k++;
			if (prefix[k]-prefix[i-1] == sum/2) kq = max(kq,j-i+1);
		} 
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
