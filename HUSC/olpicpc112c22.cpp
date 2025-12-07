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

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> matrix(n,vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> matrix[i][j];
	}
	int r, s; cin >> r >> s;
	vector<vector<int>> xuly(n,vector<int>(m-s+1));
	for (int i = 0; i < n; i++) {
		deque<int> dq;
		for (int j = 0; j < m; j++) {
			while(!dq.empty() && matrix[i][dq.back()] <= matrix[i][j]) dq.pop_back();
			dq.push_back(j);
			if (j >= s-1) {
				xuly[i][j-s+1] = matrix[i][dq.front()];
				if (dq.front() == j-s+1) dq.pop_front();
			}
		}
	}
	vector<vector<int>> kq(n-r+1,vector<int>(m-s+1));
	for (int j = 0; j < m-s+1; j++) {
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			while(!dq.empty() && xuly[dq.back()][j] <= xuly[i][j]) dq.pop_back();
			dq.push_back(i);
			if (i >= r-1) {
				kq[i-r+1][j] = xuly[dq.front()][j];
				if (dq.front() == i-r+1) dq.pop_front();
			}
		}
	}
	for (int i = 0; i < n-r+1; i++) {
		for (int j = 0; j < m-s+1; j++) cout << kq[i][j] << " ";
		cout << endl;
	}
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
