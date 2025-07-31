#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e5+1;
const int MOD = 1e9+7;
const string NoF = "Name_of_File";
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
void solve() {
	int n, m; cin >> n >> m;
	int grid[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> grid[i][j];
	}
	vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
	dp[0][0] = 0;
	queue<pair<int,int>> q;
	q.push({0,0});
	while (!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dp[nx][ny] > dp[x][y]+1) {
				dp[nx][ny] = dp[x][y]+1;
				q.push({nx,ny});
			}
		}
		if (grid[x][y] == 0) continue;
		for (int i = x-1; i >= 0; i--) {
			if (dp[i][y] > dp[x][y]+1) {
				dp[i][y] = dp[x][y]+1;
				q.push({i,y});
			}
			if (grid[i][y] == 1) break;
		}
		for (int i = x+1; i < n; i++) {
			if (dp[i][y] > dp[x][y]+1) {
				dp[i][y] = dp[x][y]+1;
				q.push({i,y});
			}
			if (grid[i][y] == 1) break;
		}
		for (int i = y+1; i < m; i++) {
			if (dp[x][i] > dp[x][y]+1) {
				dp[x][i] = dp[x][y]+1;
				q.push({x,i});
			}
			if (grid[x][i] == 1) break;
		}
		for (int i = y-1; i >= 0; i--) {
			if (dp[x][i] > dp[x][y]+1) {
				dp[x][i] = dp[x][y]+1;
				q.push({x,i});
			}
			if (grid[x][i] == 1) break;
		}
	}
	cout << dp[n-1][m-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
