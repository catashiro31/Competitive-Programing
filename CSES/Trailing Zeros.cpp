#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
long kq(long n) {
	if (n == 0) return 0;
	return n/5 + kq(n/5);
}
void solve() {
	long n; cin >> n;
	cout << kq(n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdin);
	solve();
}
