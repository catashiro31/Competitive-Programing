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
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << 0;
		else if (i == 2) cout << 6;
		else if (i == 3) cout << 28;
		else if (i == 4) cout << 96;
		else if (i == 5) cout << 252;
		else {
			ll size = 1LL*i*i;
			ll p = i-4;
			ll tmp = 1LL*4*(size-3) + 1LL*8*(size-4) + 1LL*(4+p*4)*(size-5) + 1LL*(p*4)*(size-7) + 1LL*p*p*(size-9);
			cout << tmp/2;
		}
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
