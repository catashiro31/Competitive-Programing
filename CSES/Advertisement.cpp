#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	stack<ll> mst;
	vector<ll> left(n,-1), right(n,n);
	for (int i = 0; i < n; i++) {
		while (!mst.empty() && a[mst.top()] >= a[i]) mst.pop();
		if (!mst.empty()) left[i] = mst.top();
		mst.push(i);
	}
	while (!mst.empty()) mst.pop();
	for (int i = n-1; i >= 0; i--) {
		while (!mst.empty() && a[mst.top()] >= a[i]) mst.pop();
		if (!mst.empty()) right[i] = mst.top();
		mst.push(i);
	}
	ll kq = 0;
	for (int i = 0; i < n; i++) {
		kq = max(kq,(right[i]-left[i]-1)*a[i]);
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}