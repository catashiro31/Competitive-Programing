#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	long S, N; cin >> S >> N;
	vector<pair<long,long>> group[S+1];
	for (int i = 0; i < N; i++) {
		long v, w, k; cin >> v >> w >> k;
		group[w].pb({v,k});
	}
	vector<long> dp(S+1,LONG_MIN);
	dp[0] = 0;
	for (int i = 0; i <= S; i++) {
		if (group[i].empty()) continue;
		sort(group[i].begin(),group[i].end(),greater<>());
		int c = 1, id = 0, k = 1;
		while (c <= S/i && id < group[i].size()) {
			for (int j = S; j >= i; j--) {
				if (dp[j-i] == LONG_MIN) continue;
				dp[j] = max(dp[j],dp[j-i] + group[i][id].fi);
			}
			if (k == group[i][id].se) k = 1, id++;
			else k++;
			c++;
		}
	}
	cout << *max_element(dp.begin(),dp.end());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	solve();
}
