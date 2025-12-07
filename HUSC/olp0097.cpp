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

vector<vector<int>> multi(const vector<vector<int>> &A, const vector<vector<int>> &B) {
	vector<vector<int>> res(A.size(),vector<int>(B[0].size()));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			res[i][j] = 0;
			for (int k = 0; k < A[0].size(); k++) res[i][j] = (res[i][j] + (A[i][k] * B[k][j])) % MOD;
		}
	}
	return res;
}

vector<vector<int>> powup(vector<vector<int>> base, int exp) {
	vector<vector<int>> res(base.size(),vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = multi(res,base);
		base = multi(base,base);
		exp /= 2;
	}
	return res;
}

void solve() {
	int n, k, src, dst; cin >> n >> k >> src >> dst;
	--src, --dst;
	vector<vector<int>> matrix(n,vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j ++) cin >> matrix[i][j];
	}
	vector<vector<int>> kq = powup(matrix,k);
	cout << kq[src][dst];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
