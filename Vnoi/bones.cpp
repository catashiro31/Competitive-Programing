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
	vi s(3);
	cin >> s[0] >> s[1] >> s[2];
	int sum = s[0]+s[1]+s[2];
	vector<vi> dp(3,vi(sum+1,0));
	REP(i,3) FOR(j,1,s[i]) {
		if (i == 0) dp[i][j] = 1;
		else FOR(k,1,sum-j) dp[i][k+j] += dp[i-1][k];
	}
	int cmax = 0, nub = 0;
	FOR(i,1,sum) if (dp[2][i] > cmax) cmax = dp[2][i], nub = i;
	cout << nub;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
