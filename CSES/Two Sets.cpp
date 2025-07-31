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
	vector<bool> c(n+1,true);
	ll sum = 1LL*n*(n+1);
	sum /= 2;
	if (sum % 2) {
		cout << "NO";
		return;
	} else sum /= 2;
	int sl = 0;
	for (int i = n; i > 0; i--) {
		if (sum >= i) {
			c[i] = false;
			sl++;
			sum -= i;
		}
	}
	if (sum == 0) {
		cout << "YES" << endl;
		cout << sl << endl;
		for (int i = 1; i <= n; i++) {
			if (!c[i]) cout << i << " ";
		}
		cout << endl;
		cout << n-sl << endl;
		for (int i = 1; i <= n; i++) {
			if (c[i]) cout << i << " ";
		}
	} else cout << "NO";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
