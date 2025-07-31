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
int dx[] = {0,-1,1};
int dy[] = {1,1,1};
void solve() {
	int m, n; cin >> m >> n;
	vector<vi> grid(m,vi (n));
	REP(i,m) REP(j,n) cin >> grid[i][j];
	vector<vi> dp(m,vi (n,-INF));
	REP(i,n) REP(j,m) {
		if (i == 0) dp[j][i] = grid[j][i];
		REP(k,3) {
			int x = j+dx[k], y = i+dy[k];
			if (x >= 0 && x < m && y >= 0 && y < n) 
				dp[x][y] = max(dp[x][y],dp[j][i]+grid[x][y]);
		}
	}
	int kq = -INF;
	REP(i,m) kq = max(kq,dp[i][n-1]);
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
