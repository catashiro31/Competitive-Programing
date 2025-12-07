#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
vector<int> snt;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	for (int x : snt) {
		for (int i = 0; i < n; i++) {
			if (gcd(x,a[i]) == 1) {
				cout << x << endl;
				return;
			}
		} 
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<bool> c(1e4+5,false);
	for (int i = 2; i <= 1e4; i++) {
		if (c[i]) continue;
		snt.psb(i);
		for (int j = i*i; j <= 1e4; j+=i) c[j] = true;
	}
	
	int t = 1; cin >> t;
	while(t--) solve();
}