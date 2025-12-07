#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, k; cin >> n >> x >> k;
	vector<pair<int,int>> edges;
	for (int i = 0; i < 3*n; i++) {
		if (i < 2*n) {
			edges.psb({i,i+n});
			edges.psb({i+n,i});
		}
		if (i % n == n-1) {
			edges.psb({i,i-n+1});
			edges.psb({i-n+1,i});
		} else {
			edges.psb({i,i+1});
			edges.psb({i+1,i});
		}
	}
	int m = edges.size();
	vector<vector<int>> matrix(m,vector<int>(m,0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (edges[i].se != edges[j].fi || edges[i].fi == edges[j].se) continue;
			matrix[i][j]++;
		}
	}
	
	auto multi = [&](const vector<vector<int>> &A, const vector<vector<int>> &B) {
		vector<vector<int>> res(A.size(), vector<int>(B[0].size(),0));
		int n1 = A.size();
		int n2 = A[0].size();
		int n3 = B[0].size();
		for (int i = 0; i < n1; ++i) {
		    for (int k = 0; k < n2; ++k) {
		        int a = A[i][k];
		        if (a == 0) continue;
		        const vector<int> &Bk = B[k];
		        for (int j = 0; j < n3; ++j) {
		            res[i][j] = (res[i][j] + a * Bk[j]) % MOD;
		        }
		    }
		}
		return res;
	};
	vector<vector<int>> res(matrix.size(),vector<int>(matrix.size(),0));
	for (int i = 0; i < matrix.size(); i++) res[i][i] = 1;
	k = k-1;
	while(k) {
		if (k&1) res = multi(res, matrix);
		matrix = multi(matrix,matrix);
		k>>=1;
	}
	int kq = 0;
	for (int i = 0; i < m; i++) {
		if (edges[i].fi != 0) continue;
		for (int j = 0; j < m; j++) {
			if (edges[i].fi == 0 && edges[j].se == x-1) kq = (kq + res[i][j]) % MOD;
		}
	}
	cout << kq;
}