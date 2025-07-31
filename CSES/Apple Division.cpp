#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
int n;
vector<ll> arr;
vector<int> c;
ll kq = LLONG_MAX;
void Try(int i) {
	if (i == n) {
		ll a = 0, b = 0;
		for (int j = 0; j < n; j++) {
			if (c[j]) a += arr[j];
			else b += arr[j];
		}
		kq = min(kq,abs(a-b));
		return;
	}
	for (int j = 0; j < 2; j++) {
		c[i] = j;
		Try(i+1);
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		arr.pb(x);
		c.pb(-1);
	}
	Try(0);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
