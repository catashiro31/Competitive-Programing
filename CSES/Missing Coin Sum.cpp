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
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	sort(arr.begin(),arr.end());
	ll x = 1LL;
	for (int i = 0; i < n; i++) {
		if (arr[i] > x) {
			cout << x;
			return;
		}
		x += arr[i];
	}
	cout << x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
