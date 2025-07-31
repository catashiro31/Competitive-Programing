#include <bits/stdc++.h>
#define endl '\n'
#define mod 10000000007
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int,int> A, B, F;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> F.first >> F.second;
	queue<pair<int,int>> q;
	vector<vector<int>> Visited(n+1,vector<int> (n+1,-1));
	q.push(F); Visited[F.first][F.second] = 0;
	int dx[] = {-2, -2, -1, -1,  2,  2,  1,  1};
	int dy[] = { 1, -1,  2, -2,  1, -1,  2, -2};
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int u = x + dx[i];
			int v = y + dy[i];
			if (u > 0 && u <= n && v > 0 && v <= n) {
				if (Visited[u][v] != -1) continue;
				q.push({u,v});
				Visited[u][v] = Visited[x][y]+1;
			}
		}
	}
	if (Visited[A.first][A.second] == Visited[B.first][B.second]) cout << 0 << endl;
	else if (Visited[A.first][A.second] < Visited[B.first][B.second] && Visited[A.first][A.second] != -1) cout << 1 << endl;
	else cout << 2 << endl;
	cout << Visited[A.first][A.second] << " " << Visited[B.first][B.second];
}
