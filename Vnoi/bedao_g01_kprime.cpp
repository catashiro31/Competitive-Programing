#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int n, k; cin >> n >> k;
	const int maxn = 1e7;
	vector<bool> c(maxn+1,false);
	vector<int> snt;
	for (int i = 2; i <= maxn; i++) {
		if (c[i]) continue;
		snt.psb(i);
		if (i > sqrt(maxn)) continue;
		for (int j = i*i; j <= maxn; j+=i) c[j] = true;
	}
	ll kq = 0;
	for (int i = 0; i < snt.size(); i++) {
		if (snt[i] > n) break;
		if (i < k-1) continue;
		if (i == k-1) {
			kq += 1LL*snt[i-k+1]*(n-snt[i]+1);
		} else {
			kq += 1LL*(snt[i-k+1]-snt[i-k])*(n-snt[i]+1);
		}
	}
	cout << kq << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
