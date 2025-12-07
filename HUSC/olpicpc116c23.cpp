#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

struct point {
	int x, y, z;
};

void solve() {
	int n; cin >> n;
	point src, dst;
	cin >> src.x >> src.y >> src.z;
	cin >> dst.x >> dst.y >> dst.z;
	src.x--, src.y--, src.z--;
	dst.x--, dst.y--, dst.z--;
	vector<vector<vector<bool>>> is_block(n,vector<vector<bool>>(n,vector<bool>(n)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string s; cin >> s;
			for (int k = 0; k < n; k++) {
				if (s[k] == '1') is_block[i][j][k] = true; 
				else is_block[i][j][k] = false;
			}
		}
	}
	int go_x[6] = {1,0,0,-1, 0, 0};
	int go_y[6] = {0,1,0, 0,-1, 0};
	int go_z[6] = {0,0,1, 0, 0,-1};
	vector<vector<vector<int>>> dist(n,vector<vector<int>>(n,vector<int>(n,-1)));
	dist[src.z][src.x][src.y] = 0;
	queue<point> q;
	q.push(src);
	while (!q.empty()) {
		point u = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			point v;
			v.x = u.x + go_x[i], v.y = u.y + go_y[i], v.z = u.z + go_z[i];
			if (v.x >= 0 && v.x < n && v.y >= 0 && v.y < n && v.z >= 0 && v.z < n && !is_block[v.z][v.x][v.y] && dist[v.z][v.x][v.y] == -1) {
				dist[v.z][v.x][v.y] = dist[u.z][u.x][u.y] + 1;
				q.push(v);
			}
		}
	}
	cout << dist[dst.z][dst.x][dst.y];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
