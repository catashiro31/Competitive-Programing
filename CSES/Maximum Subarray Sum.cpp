#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<long> a(n);
	for (long &x : a) cin >> x;
	vector<ll> prefix(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) prefix[i] = a[i];
		else prefix[i] = prefix[i-1] + a[i];
	}
	ll cmin = 0;
	vector<ll> kq(n);
	for (int i = 0; i < n; i++) {
		if (i != 0) cmin = min(cmin,prefix[i-1]);
		kq[i] = prefix[i] - cmin;
	}
	cout << *max_element(kq.begin(),kq.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
