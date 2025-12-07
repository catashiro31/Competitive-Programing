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

struct block{
	int h, a, c;
};
void solve() {
	int k; cin >> k;
	vector<block> K(k);
	for (int i = 0; i < k; i++) cin >> K[i].h >> K[i].a >> K[i].c;
	sort(all(K),[](auto &x, auto &y){
		return x.a < y.a;	
	});
	vector<bool> dp(40005,false);
	dp[0] = true;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < K[i].c; j++) {
			for (int v = K[i].a; v >= K[i].h; v--) {
				if (dp[v-K[i].h]) dp[v] = true;
			}
		}
	}
	for (int i = 40005; i>= 0; i--) {
		if (dp[i]) {
			cout << i << endl;
			break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
