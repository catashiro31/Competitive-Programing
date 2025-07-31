#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
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
#define mod 14062008
using ll = long long;
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	vll dp(n+1,0);
	REP(i,k) {
		int x; cin >> x;
		dp[x-1] = -1;
	}
	dp[0] = 1;
	FOR(i,1,n-1) 
		if (dp[i] != -1) 
			FOR(j,1,min(2,i)) if (dp[i-j] != -1) dp[i] = (dp[i]+dp[i-j])%mod;
	cout << dp[n-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
