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
	vector<vector<int>> res(A.size(), vector<int>(B.size(),0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) {
				res[i][j] = (res[i][j] + A[i][k]*B[k][j]) % MOD; 
			}
		}
	}
	return res;
}

vector<vector<int>> powup(vector<vector<int>> base, int exp) {
	vector<vector<int>> res(base.size(), vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = multi(res,base);
		base = multi(base,base);
		exp /= 2;
	}
	return res;
}

void solve() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int n; cin >> n;
	vector<vector<int>> f(1,vector<int>(4));
	f[0][0] = a, f[0][1] = b, f[0][2] = c, f[0][3] = d;
	vector<vector<int>> matrix(4,vector<int>(4));
	matrix[0] = {3,1,0,0};
	matrix[1] = {2,0,0,0};
	matrix[2] = {2,0,1,1};
	matrix[3] = {3,0,2,0};
	if (n < 2) {
		cout << f[0][1-n];
		return;
	}
	matrix = powup(matrix,n-1);
	f = multi(f,matrix);
	cout << f[0][0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
