#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

vector<double> khu_gauss(vector<vector<double>>& A) {
	int n = sz(A);
	for (int j = 0; j < n; j++) {
		int pos = j;
		for (int i = j + 1; i < n; i++) {
			if (abs(A[i][j]) > abs(A[pos][j])) pos = i;
		}
		swap(A[j], A[pos]);
		if (abs(A[j][j]) < 1e-6) continue;
		for (int i = j + 1; i < n; i++) {
			double val = A[i][j] / A[j][j];
			for (int k = j; k <= n; k++) A[i][k] -= val * A[j][k];
		}
	}
	vector<double> x(n,0);
	for (int i = n - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < n; ++j) sum += A[i][j] * x[j];
		if (abs(A[i][i]) < 1e-9) x[i] = 0;
		else x[i] = 1.0*(A[i][n] - sum) / A[i][i];
	}
	return x;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> deg(n,0);
	vector<vector<int>> adj(n);
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		deg[u]++, deg[v]++;
		adj[u].psb(v);
		adj[v].psb(u);
		edges.psb({u, v});
	}
 	vector<vector<double>> matrix(n, vector<double>(n+1, 0.0));
 	
	for (int u = 0; u < n - 1; u++) {
		matrix[u][u] = 1.0;
 	 	if (u == 0) matrix[u][n] = 1.0;
 	 	else {
 	 	 	matrix[u][n] = 0.0;
 	 	}
 	 	for (int v : adj[u]) {
 	 	 	if (v != n - 1) {
 	 	 	 	matrix[u][v] -= (1.0 / deg[v]);
 	 	 	}
 	 	}
 	}
    matrix[n-1][n-1] = 1.0, matrix[n-1][n] = 0.0;
 	vector<double> gauss = khu_gauss(matrix);
 	vector<double> ky_vong;
 	for (auto edge : edges) {
		auto [u,v] = edge;
 	 	double e = (gauss[u] / deg[u]) + (gauss[v] / deg[v]);
 	 	ky_vong.psb(e);
 	}
 	sort(all(ky_vong),greater<double>());
 	double kq = 0.0;
 	for (int i = 0; i < m; i++) kq += ky_vong[i] * (i + 1);
 	cout << fixed << setprecision(3) << kq << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}