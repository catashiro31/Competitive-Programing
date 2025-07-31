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
int DFS(int x, int y, int len, vector<vector<int>> grid, int c) {
	if (len == 1) {
		if (grid[x][y] == c) return 1;
		return 0;	
	}
	int nlen = len/2;
	int ul = DFS(x,y,nlen,grid,c);
	int dr = DFS(x+nlen,y+nlen,nlen,grid,c);
	int dl = DFS(x+nlen,y,nlen,grid,c);
	int ur = DFS(x,y+nlen,nlen,grid,c);
	if (ul == 1 && ur == 1 && dl == 1 && dr == 1) return 1;
	return ul + dr + dl + ur;
}
void solve() {
	int t; cin >> t;
	for (int q = 1; q <= t; q++) {
		int n; cin >> n;
		vector<vector<int>> grid(n,vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> grid[i][j];
		} 
		cout << "#" << q << " " << DFS(0,0,n,grid,0) << " " << DFS(0,0,n,grid,1) << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
