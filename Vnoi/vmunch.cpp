#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define LINF 1e18
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
#define fo(i,a,b) for(int i=(a); i <= (b); ++i)
#define fod(i,a,b) for(int i=(b); i >= (a); --i)
#define rep(i,n) for(int i= 0; i < (n); ++i)
#define repd(i,n) for(int i= (n)-1; i >= 0; --i)
#define mod 1000000007
using ll = long long;
using namespace std;
void solve() {
	int r,c; cin >> r >> c;
	int dr[] = {-1,0,1,0};
	int dc[] = {0,-1,0,1};
	vector<vector<char>> grid(r,vector<char>(c));
	queue<pii> q;
	vector<vi> kq(r,vi(c,-1));
	rep(i,r) rep(j,c) {
		cin >> grid[i][j];
		if (grid[i][j] == 'C') {
			q.push({i,j});
			kq[i][j] = 0;		
		}
	}
	while(!q.empty()) {
		int x = q.front().fi, y = q.front().se;
		if (grid[x][y] == 'B') {
			cout << kq[x][y];
			return;
		}
		q.pop();
		rep(i,4) {
			int nr = x + dr[i], nc = y + dc[i];
			if (nr >= 0 && nc >= 0 && nr < r && nc < c && kq[nr][nc] == -1 &&  grid[nr][nc] != '*') {
				kq[nr][nc] = kq[x][y] + 1;
				q.push({nr,nc});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}