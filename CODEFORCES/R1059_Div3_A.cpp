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
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	int kq = -1;
	for (int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			kq = max(kq, (prefix[j]-prefix[i-1])/(j-i+1));
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
