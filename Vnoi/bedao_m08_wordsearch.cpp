#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define mod 1000000007
using ll = long long;
using namespace std;
const string NoF = "Name_of_File";
int dx[] = {1,0,-1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<string> tb(n);
	for (string &x : tb) cin >> x;
	while (q--) {
		string s; cin >> s;
		bool kq = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vector<bool> c(8,true);
				for (int k = 0; k < s.length(); k++) {
					for (int h = 0; h < 8; h++) {
						if (!c[h]) continue;
						int x = i + k*dx[h], y = j + k*dy[h];
						if (x < 0 || x >= n || y < 0 || y >= m || s[k] != tb[x][y]) {
							c[h] = false;
							continue;
						}
					}
				}
				for (int h = 0; h < 8; h++) kq = (c[h] || kq);
				if (kq) break;
			}
			if (kq) break;
		}
		if (kq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
//	freopen((NoF + ".in").c_str(),"r",stdin);
//	freopen((NoF + ".out").c_str(),"w",stdout);
	solve();
}
