#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, q; cin >> n >> q;
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	sort(arr.begin(),arr.end());
	while (q--) {
		long a, b; cin >> a >> b;
		int r = upper_bound(arr.begin(),arr.end(),b) - arr.begin();
		int l = lower_bound(arr.begin(),arr.end(),a) - arr.begin();
		if (l == 0) cout << r << endl;
		else cout << r - l << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
	solve();
}
