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
	string str; cin >> str;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') continue;
		bool c = false;
		for (int j = i-1; j >= max(0LL,i-k+1); j--) {
			if (str[j] == '1') c = true;
		}
		if (!c) kq++;
	}
	cout << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
