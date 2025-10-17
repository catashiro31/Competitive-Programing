#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
vector<vector<ll>> mul(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
	vector<vector<ll>> res(A.size(), vector<ll>(B[0].size(),LLONG_MAX));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) {
				if (A[i][k] == LLONG_MAX || B[k][j] == LLONG_MAX) continue;
				res[i][j] = min(res[i][j],A[i][k]+B[k][j]);
			}
		}
	}
	return res;
}

vector<vector<ll>> pow_up(vector<vector<ll>> base, int exp) {
	vector<vector<ll>> res(base.size(),vector<ll>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = mul(res,base);
		base = mul(base,base);
		exp /= 2;
	}	
	return res;
}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<ll>> mat(n,vector<ll>(n,LLONG_MAX));
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		mat[u][v] = c;
	}
	mat = pow_up(mat,k);
	ll kq = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) kq = min(kq,mat[i][j]);
	}
	if (kq == LLONG_MAX) cout << "IMPOSSIBLE" << endl;
	else cout << kq << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
	return 0;
}
