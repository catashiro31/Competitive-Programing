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
	vector<ll> arr(n);
	for (ll &x : arr) cin >> x;
	sort(arr.begin(),arr.end());
	//
	vector<ll> prefix(n);
	for (int i = 0; i < n; i++) {
		if (i == 0) prefix[i] = arr[i];
		else prefix[i] = prefix[i-1] + arr[i];
	}
	// RIGHT
	vector<ll> right(n);
	int r = n-1;
	for (int i = r; i >= 0; i--) {
		int m = (i+r)/2;
		ll mr = prefix[r] - prefix[m];
		ll lm;
		if (i) lm = prefix[m-1] - prefix[i-1];
		else lm = prefix[m-1]; 
		right[i] = mr - arr[m]*(r-m) + (m-i)*arr[m] - lm; 
	}
//	for (ll x : right) cout << x << " ";
	// LEFT
	vector<ll> left(n);
	int l = 0;
	for (int i = 0; i < n; i++) {
		int m = (i+l)/2;
		ll mr = prefix[i] - prefix[m];
		ll lm;
		if (m) lm = prefix[m-1];
		else lm = 0;
		left[i] = mr - arr[m]*(i-m) + (m-l)*arr[m] - lm;
	}
//	for (ll x : left) cout << x << " ";
	// KQ
	ll kq = LLONG_MAX;
	for (int i = 0; i < n-1; i++) kq = min(left[i]+right[i+1],kq);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
