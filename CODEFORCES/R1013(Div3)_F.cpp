#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using OST =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define endl '\n'
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int MAXN = 2e3;
const int MOD = 998244353;
const string NoF = "Name_of_File";
int n, m, d;
ll dp[MAXN][MAXN][2], prefix[MAXN][MAXN][2];
ll getprefix(int i, int j, int l, int r, int f) {
	ll ans = prefix[i][min(m-1,r)][f];
	if (l > 0) ans = ((ans - prefix[i][l-1][f])%MOD + MOD)%MOD;
	return ans;
}
void solve() {
	cin >> n >> m >> d;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) cin >> grid[i];
	for (int i = n-1; i >= 0; i--) {
		for (int f = 0; f < 2; f++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '#') dp[i][j][f] = 0;
				else {
					if (f == 0) {
						if (i == n-1) dp[i][j][f] = 1;
						else {
							int dl = sqrt(d*d-1);
							int l = j-dl, r = j+dl;
							dp[i][j][f] = (getprefix(i+1,j,l,r,0) + getprefix(i+1,j,l,r,1))%MOD;
						}
					} else {
						int l = j-d, r = j+d;
						dp[i][j][f] = (getprefix(i,j,l,j-1,0)+getprefix(i,j,j+1,r,0))%MOD;
					}
				}
			}
			prefix[i][0][f] = dp[i][0][f];
			for (int j = 1; j < m; j++) prefix[i][j][f] = (prefix[i][j-1][f]+dp[i][j][f])%MOD;
		}
	}
	ll kq = 0;
	for (int i = 0; i < m; i++) kq = (kq + dp[0][i][0] + dp[0][i][1])%MOD;
	cout << kq << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	int t; cin >> t;
	while(t--) {
		memset(dp,0,sizeof(dp));
		memset(prefix,0,sizeof(prefix));
		solve();
	}
}
