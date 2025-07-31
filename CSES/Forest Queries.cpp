#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int n, q; cin >> n >> q;
	vector<vector<int>> grid(n+1,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') grid[i][j+1] = 1;
			else grid[i][j+1] = 0;
		}
	}
	vector<vector<int>> prefix2D = grid;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) prefix2D[i][j] += prefix2D[i][j-1] + prefix2D[i-1][j] - prefix2D[i-1][j-1];
	}
	while(q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << prefix2D[y2][x2] + prefix2D[y1-1][x1-1] - prefix2D[y2][x1-1] - prefix2D[y1-1][x2] << endl;
	}
}	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	solve();
}
