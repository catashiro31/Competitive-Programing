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
	int q; cin >> q;
	vector<long> arr(n);
	for (long &x : arr) cin >> x;
	for (int i = 1; i < n; i++) arr[i] += arr[i-1];
	while (q--) {
		int a,b; cin >> a >> b;
		--a, --b;
		if (a == 0) cout << arr[b];
		else cout << arr[b] - arr[a-1];
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
