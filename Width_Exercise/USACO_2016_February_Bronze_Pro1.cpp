#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int x, y, m; cin >> x >> y >> m;
	vector<bool> dp(m+1,false);
	dp[0] = true;
	for (int i = 0; i <= m-x; i++) dp[i+x] = (dp[i+x] || dp[i]);
	for (int i = 0; i <= m-y; i++) dp[i+y] = (dp[i+y] || dp[i]);
	while (!dp[m]) m--;
	cout << m;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("pails.in","r",stdin);
	freopen("pails.out","w",stdout);
	solve();
}
