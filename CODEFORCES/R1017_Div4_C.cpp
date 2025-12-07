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
	int n; cin >> n;
	vector<bool> used(2*n+1,false);
	vector<int> kq(2*n,-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			used[x] = true;
			kq[i+j+1] = x;
		}
	}
	vector<int> not_used;
	for (int i = 1; i <= 2*n; i++) if (!used[i]) not_used.psb(i);
	int j = 0;
	for (int i = 0; i < 2*n; i++) {
		if (kq[i] == -1) kq[i] = not_used[j], j++;
	}
	for (int x : kq) cout << x << " ";
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
