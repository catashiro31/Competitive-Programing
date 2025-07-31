#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<long> prefix(n+1,0);
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
	vector<vector<long>> dp(n+1,vector<long>(n+1,0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n-i; j++) {
			dp[j][j+i] = min(dp[j][j+i-1],dp[j+i-1][j]) + prefix[j+i] - prefix[j-1];
			dp[j+i][j] = min(dp[j+i][j+1],dp[j+1][j+i]) + prefix[j+i] - prefix[j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << dp[i][j] << " ";
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
