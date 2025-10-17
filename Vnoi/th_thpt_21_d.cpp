#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()

void solve() {
	int l, r; cin >> l >> r;
	vector<bool> c(1e6+1,false);
	vector<int> snt;
	for (int i = 2; i*i <= 1e6; i++) {
		if (c[i]) continue;
		snt.psb(i);
		if (i > sqrt(1e6)) continue;
		for (int j = i*i; j <= 1e6; j+=i) c[j] = true; 
	}
	vector<int> kq;
	for (int i = 0; i < snt.size(); i++) {
		for (int j = 1; j < snt.size(); j++) {
			if (pow(snt[i],snt[j]-1) <= 1e6) kq.push_back(pow(snt[i],snt[j]-1));
		}
	}
	sort(all(kq));
//	for (int x : kq) cout << x << " ";
	cout << upper_bound(all(kq),r) - lower_bound(all(kq),l) << endl;
}
int main() {
	freopen("BAI4.INP","r",stdin);
	freopen("BAI4.OUT","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
