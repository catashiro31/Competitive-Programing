#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
void solve() {
	int x, y; cin >> x >> y;
	vector<vector<bool>> c(1e3+1,vector<bool>(1e3+1,true));
	queue<pair<int,int>> q;
	q.push({x,y});
	c[x][y] = false;
	int kq = 1;
	while (!q.empty()) {
		int u = q.front().fi, v = q.front().se;
		q.pop();
		if (u % 2 == 0 && c[v][u/2]) {
			kq++;
			q.push({v,u/2});
			c[v][u/2] = false;
		}
		if (v % 2 == 1 && c[(v+1)/2][u]) {
			kq++;
			q.push({(v+1)/2,u});
			c[(v+1)/2][u] = false;
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
