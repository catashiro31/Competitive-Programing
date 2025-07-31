#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "pails";
void solve() {
	int x, y, k, m; cin >> x >> y >> k >> m;
	vector<vector<int>> c(x+1,vector<int>(y+1,-1));
	queue<pair<int,int>> q;
	q.push({0,0});
	c[0][0] = 0;
	set<int> s; s.insert(0);
	while (!q.empty()) {
		auto [nx,ny] = q.front(); q.pop();
		int d = c[nx][ny];
		s.insert(nx + ny);
		if (d + 1 > k) continue;
		if (c[x][ny] == -1) {
			q.push({x,ny});
			c[x][ny] = d + 1;
		}
		if (c[nx][y] == -1) {
			q.push({nx,y});
			c[nx][y] = d + 1;
		}
		if (c[0][ny] == -1) {
			q.push({0,ny});
			c[0][ny] = d + 1;
		}
		if (c[nx][0] == -1) {
			q.push({nx,0});
			c[nx][0] = d + 1;
		}
		if (nx + ny <= x) {
			if (c[nx+ny][0] == -1) {
				q.push({nx+ny,0});
				c[nx+ny][0] = d + 1;
			}
		} else {
			if (c[x][nx+ny-x] == -1) {
				q.push({x,nx+ny-x});
				c[x][nx+ny-x] = d + 1;
			}
		}
		if (nx + ny <= y) {
			if (c[0][nx+ny] == -1) {
				q.push({0,nx+ny});
				c[0][nx+ny] = d + 1;
			}
		} else {
			if (c[nx+ny-y][y] == -1) {
				q.push({nx+ny-y,y});
				c[nx+ny-y][y] = d + 1;
			}
		}
	}
	int kq = INT_MAX;
	auto it = s.lower_bound(m);
	if (it != s.end()) kq = min(kq,abs(m-*it));
	if (it != s.begin()) {
		it = prev(it);
		kq = min(kq,abs(m-*it));
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen((NoF + ".in").c_str(),"r",stdin);
	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
