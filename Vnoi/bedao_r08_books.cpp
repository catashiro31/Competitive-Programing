#include <bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, q; cin >> n >> q;
	vector<bool> check(n,false);
	vector<int> arr(q);
	for (int &x : arr) cin >> x;
	for (int i = q-1; i >= 0; i--) {
		if (check[arr[i]-1]) continue;
		else {
			check[arr[i]-1] = true;
			cout << arr[i] << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) cout << i+1 << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
