#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int h, w; 
vector<vector<int>> grid(4000,vector<int>(4000,0));
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool inside(int x, int y) {
	return (0 <= x && x < h && 0 <= y && y < w && grid[x][y] == 0);
}
void solve() {
	cin >> h >> w;
	vector<string> snow(h);
	for (string &x : snow) cin >> x;
	deque<pair<int,int>> dq;
	dq.push_back({0,0});
	grid[0][0] = 1;
	int kq = 0;
	while (!dq.empty()) {
		auto [u,v] = dq.front();
		dq.pop_front();
		kq = max(kq,grid[u][v]);
		for (int i = 0 ; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if (!inside(x,y) || snow[x][y] == '.' ) continue;
			if (snow[u][v] == snow[x][y]) {
				dq.push_front({x,y});
				grid[x][y] = grid[u][v];
			}
			else {
				dq.push_back({x,y});
				grid[x][y] = grid[u][v] + 1;
			}
		}
	}
	cout << kq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
