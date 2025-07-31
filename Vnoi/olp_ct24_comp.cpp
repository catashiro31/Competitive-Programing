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
	n--;
	while (n > 1) {
		int tmp = log2(n);
		tmp = pow(2,tmp);
		n -= tmp;
		for (int i = 0; i <= n; i++) a[i] ^= a[i+tmp];
	} 
	if (n == 1) a[0] ^= a[1];
	cout << a[0]; 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
