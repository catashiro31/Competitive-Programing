#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int long long
#define MOD 1000000007
#define MAXN 200005

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B, int m) {
	vector<vector<int>> res(sz(A), vector<int>(sz(B[0])));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) res[i][j] = (res[i][j] + (A[i][k] * B[k][j]) % m + m) % m;
		}
	}
	return res;
}

vector<vector<int>> powup(vector<vector<int>> base, int exp, int m) {
	vector<vector<int>> res(base.size(), vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = mul(res,base,m);
		base = mul(base,base,m);
		exp /= 2;
	}
	return res;
}

void solve() {
	int a2, n, m; cin >> a2 >> n >> m;
	vector<vector<int>> base(1,vector<int>(4));
	base[0][0] = 1, base[0][1] = (a2*a2)%m, base[0][2] = a2%m, base[0][3] = (base[0][0] + base[0][1]) % m;
	vector<vector<int>> f(4,vector<int>(4));
	f[0][0] = 0, f[0][1] = 1, f[0][2] = 0, f[0][3] = 1;
	f[1][0] = 1, f[1][1] = (4*a2*a2)%m, f[1][2] = (2*a2)%m, f[1][3] = (4*a2*a2)%m;
	f[2][0] = 0, f[2][1] = ((-4*a2)%m+m)%m, f[2][2] = (m-1)%m, f[2][3] = ((-4*a2)%m+m)%m;
	f[3][0] = 0, f[3][1] = 0, f[3][2] = 0, f[3][3] = 1;
	f = powup(f,n-2,m);
	vector<vector<int>> kq = mul(base,f,m);
	cout << kq[0][3] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
