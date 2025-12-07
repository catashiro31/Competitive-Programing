#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int sum = 0, kq = 0;
	map<int,int> sl;
	sl[0] = 1;
	for (int i = 0; i < n; i++){
		sum += a[i];
		kq += sl[sum-x];
		sl[sum]++;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
