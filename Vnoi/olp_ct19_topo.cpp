#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

int tranform(char x) {
	switch (x) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'a':
			return 10;
		case 'B':
			return 11;
		case 'b':
			return 11;
		case 'C':
			return 12;
		case 'c':
			return 12;
		case 'D':
			return 13;
		case 'd':
			return 13;
		case 'E':
			return 14;
		case 'e':
			return 14;
		case 'F':
			return 15;
		case 'f':
			return 15;
	}
}

int cal(int x) {
	int res = 0;
	while (x) res += (x%10), x/=10;
	if (res >= 16) return cal(res);
	return res;
}

void solve() {
	string x, y; cin >> x >> y;
	int m = sz(y);
	while (sz(x) < m) x = "0" + x;
	int cnt = 0;
	for (int i = 0; i < m; i++) if (x[i] != y[i]) cnt++;
	if (cnt == 0) cout << cal(tranform(x[m-1]));
	else {
		if (x[m-1] == y[m-1]) cout << 9;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
