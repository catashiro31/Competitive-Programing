#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
#define pii pair<int,int>
#define pli pair<long,int>
#define plli pair<ll,int>
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(x) ((x).size())
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define FOR(i,a,b) for(int i=(a); i <= (b); ++i)
#define FORD(i,a,b) for(int i=(b); i >= 0; --i)
#define REP(i,n) for(int i= 0; i < (n); ++i)
#define REPD(i,n) for(int i= (n)-1; i >= 0; --i)
using ll = long long;
using namespace std;
void solve() {
	int n; cin >> n;
	vi dis(n-1);
	for (int &x : dis) cin >> x;
	vll dp(n);
	dp[0] = 0, dp[1] = dis[0], dp[2] = dp[1] + dis[1];
	FOR(i,3,n) dp[i] = min(dp[i-1]+dis[i-1],dp[i-2]+dis[i-1]);
	cout << dp[n-1]; 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
