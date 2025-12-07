#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005
#define EPS 1e-9
void solve() {
	string str; cin >> str;
	vector<double> log_num(1e6+1,0);
	for (int i = 2; i <= 1e6; i++) log_num[i] = log_num[i-1] + log10l(i);
	auto get_num = [](string p) {
		int lenp = sz(p);
		int len = min(lenp, 15LL);
		int num = 0;
		for (int i = 0; i < len; i++) num = num*10 + p[i]-'0';
		return log10l(num) + lenp - len;
	};
	double logn = get_num(str);
	int y = 1;
	for (int x = 1; x <= 1e6; x++) {
		while (y <= 1e6 && (log_num[y] - log_num[x-1] + EPS < logn)) y++;
		if (y <= 1e6 && fabsl(log_num[y]-log_num[x-1] - logn) <= EPS) {
			cout << x << " " << y << endl;
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
