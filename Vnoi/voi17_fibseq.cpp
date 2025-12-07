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

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B, int mod) {
	vector<vector<int>> res(A.size(),vector<int>(B[0].size(),0));
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < A[0].size(); k++) res[i][j] =  (res[i][j] + A[i][k] * B[k][j]) % mod; 
		}
	}
	return res;
}

vector<vector<int>> powup(vector<vector<int>> base, int exp, int mod) {
	vector<vector<int>> res(base.size(), vector<int>(base.size(),0));
	for (int i = 0; i < base.size(); i++) res[i][i] = 1;
	while(exp) {
		if (exp&1) res = mul(res,base, mod);
		base = mul(base,base, mod);
		exp /= 2;
	}
	return res;
}

void solve() {
	int n, ith, k; cin >> n >> ith >> k;
	vector<vector<int>> f(2,vector<int>(2));
	f[0][0] = 0, f[0][1] = 1, f[1][0] = 1, f[1][1] = 1;
	vector<vector<int>> base(1,vector<int>(2));
	base[0][0] = 1, base[0][1] = 1;
	base = mul(base,powup(f,ith-2,k),k);
	vector<int> hs(n+1,0);
	hs[0] = base[0][0], hs[1] = base[0][1];
	for (int i = 2; i <= n; i++) hs[i] = (hs[i-1]+hs[i-2])%k;
	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(k,{-1,-1}));
	dp[0][0] = {0,0};
	vector<int> path;
	for (int i = 1; i <= n; i++) {
		vector<pair<int,int>> tmp(k,{-1,-1});
		for (int j = 0; j < k; j++) tmp[j] = dp[i-1][j], dp[i][j] = dp[i-1][j];
		dp[i][0] = {-1, -1};
		for (int j = 0; j < k; j++) {
			if (tmp[j].fi == -1 || dp[i][(j + hs[i])%k].fi != -1) continue;
			dp[i][(j + hs[i])%k] = {i-1, i};
		}
		if (dp[i][0].fi == -1 && dp[i][0].se == -1) continue;
		int u = i, v = 0;
		while (u) {
			path.psb(dp[u][v].se);
			int val = hs[dp[u][v].se];
			u = dp[u][v].fi;
			v = (v-val+k)%k;
		}
		cout << path.size() << " ";
		reverse(all(path));
		for (int i = 0; i < path.size(); i++) cout << path[i]+ith-1 << " "; 
		return;
	}
	cout << 0 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; cin >> t;
	while(t--) solve();
}
