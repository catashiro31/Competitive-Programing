#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
vector<vector<int>> grid(1e3,vector<int>(1e3,INT_MAX));
vector<string> maze(1e3);
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
string t[4] = {"L","R","U","D"};
int n,m;
bool inside(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m && maze[x][y] != '#');
}
void Monster_go(vector<pair<int,int>> monsters) {
	vector<vector<bool>> c(n,vector<bool>(m,true));
	queue<pair<int,int>> q;
	for (auto [x,y] : monsters) {
		q.push({x,y});  grid[x][y] = 0;
	}
	while (!q.empty()) {
		auto [u,v] = q.front(); q.pop();
		c[u][v] = false;
		for (int i = 0; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if (!inside(x,y) || !c[x][y] || grid[u][v] + 1 >= grid[x][y]) continue;
			grid[x][y] = grid[u][v] + 1;
			q.push({x,y});
		}
	}
}
void solve() {	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> maze[i];
	
	vector<pair<int,int>> monsters;
	pair<int,int> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'M') monsters.pb({i,j});
			if (maze[i][j] == 'A') start = {i,j};
		}
	}
	
	Monster_go(monsters);
	
	vector<vector<string>> kq(n,vector<string>(m,"."));
	vector<vector<bool>> c(n,vector<bool>(m,true));
	queue<pair<int,int>> q;
	q.push(start);
	kq[start.fi][start.se] = "";
	while (!q.empty()) {
		auto [u,v] = q.front(); q.pop();
		c[u][v] = false;
		if (u == 0 || u == n-1 || v == 0 || v == m-1) {
			cout << "YES" << endl;
			cout << kq[u][v].size() << endl;
			cout << kq[u][v] << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if (!inside(x,y) || !c[x][y] || kq[u][v].size()+1 >= grid[x][y]) continue;
			kq[x][y] = kq[u][v] + t[i];
			q.push({x,y});
		}
	}
	cout << "NO";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}