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

//vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
//	vector<vector<int>> res(A.size(), vector<int>(B[0].size(),0));
//	for (int i = 0; i < A.size(); i++) {
//		for (int j = 0; j < B[0].size(); j++) {
//			for (int k = 0; k < A[0].size(); k++) {
//				res[i][j] = res[i][j] + A[i][k] * B[k][j];
//			}
//		}
//	}
//	return res;
//}
//
//vector<vector<int>> powup(vector<vector<int>> &base, int exp) {
//	vector<vector<int>> res(base.size(),vector<int>(base.size(),0));
//	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
//	while(exp) {
//		if (exp &1) res = mul(res,base);
//		base = mul(base,base);
//		exp /= 2;
//	}
//	return res;
//}

map<int,int> dp;
int cal(int x) {
	if (dp[x] != 0) return dp[x];
	if (x == 0) return 0;
	else if (x == 1) return 1;
	else if (x == 2) return 2;
	if (x % 3 == 0) {
		int k = x/3;
		return dp[x] = cal(2*k);
	} else if (x % 3 == 1) {
		int k = (x-1)/3;
		return dp[x] = cal(2*k) + cal(2*k+1);
	} else {
		int k = (x-2)/3;
		return dp[x] = cal(2*k) + cal(2*k+1) + cal(2*k+2);
	}
}

void solve() {
	cout << "Nhap n = ";
	int n; cin >> n;
	cout << "f(" << n << ") = " << cal(n) << endl;
}

signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);

	int t = 1;
	while(t--) solve();
}
