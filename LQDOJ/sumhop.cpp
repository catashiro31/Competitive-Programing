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
	vector<bool> c(1e6+5,false);
	vector<int> snt;
	for (int i = 2; i < 1e6+5; i++) {
		if (c[i]) continue;
		snt.psb(i);
		for (int j = i*i; j < 1e6; j+=i) c[j] = true;
	}
	int n; cin >> n;
	vector<int> sl(1e6+5,0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		int j = 0, root_a = sqrt(x);
		while (snt[j] <= root_a) {
			int cnt = 0;
			while (x % snt[j] == 0) x/=snt[j], cnt++;
			if (sl[snt[j]] < cnt) sl[snt[j]] = cnt; 
			j++;
		}
		if (x != 1 && sl[x] < 1) sl[x] = 1; 
	}
	int kq = 1;
	for (int i = 0; i < sz(snt); i++) {
		if (!sl[snt[i]]) continue; 
		for (int j = 0; j < sl[snt[i]]; j++) kq = (kq * snt[i]) % MOD;
	}
	cout << kq;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
