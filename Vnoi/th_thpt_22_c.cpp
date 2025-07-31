#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	string s; cin >> s;
	vector<long> sl(10,0);
	for (char x : s) sl[x-'0']++;
	if (sl[0]) {
		long sum = 0;
		for (long i = 0; i < 10; i++) sum += i*sl[];
		if (sum % 3 == 0) {
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < sl[i]; j++) cout << i;
			}
		} else cout << -1;
	} else cout << -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("MATMA.INP","r",stdin);
//	freopen("MATMA.OUT","w",stdout);
	solve();
}
