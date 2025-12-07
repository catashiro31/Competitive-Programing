#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define psb push_back
#define sz(x) x.size()
#define int unsigned long long
#define MOD 4294967296
#define MAXN 200005

bool check(int x1, int y1, int x2, int y2) {
	long long dx[] = {-1,-1,-2,-2,1,1,2,2};
	long long dy[] = {-2,2,1,-1,-2,2,-1,1};
	for (int k = 0; k < 8; k++) {
		long long nx = x1 + dx[k], ny = y1 + dy[k];
		if (nx == x2 && ny == y2) return true;
	}
	return false;
}

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) {
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector<vector<int>> pow_up(vector<vector<int>> base, int exp) {
	vector<vector<int>> res(base.size(), vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while (exp) {
		if (exp&1) res = mul(res,base);
		base = mul(base,base);
		exp /= 2;
	}
	return res;
}

void solve() {
	int k; cin >> k;
	vector<vector<int>> f(65,vector<int>(65,0));
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			int x1 = i/8, y1 = i%8;
			int x2 = j/8, y2 = j%8;
			if (check(x1,y1,x2,y2)) f[i][j] = 1;
		}
	}
	for (int j = 0; j < 64; ++j) f[j][64] = 1;
	f[64][64] = 1;
	vector<vector<int>> kq = pow_up(f,k+1);
	cout << kq[0][64];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
