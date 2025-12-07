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
	vector<string> arr(n);
	for (string &x : arr) cin >> x;
	unordered_map<string,int> sl;
	for (int i = 0; i < n; i++) {
		if (sl[arr[i]] == 0) cout << "OK" << endl;
		else {
			cout << arr[i] << sl[arr[i]] << endl;
		}
		sl[arr[i]]++;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
